#!/usr/bin/env python3
"""Compile and link an independent consumer of a prepared Core binary package."""

import argparse
import json
from pathlib import Path
import shutil
import subprocess


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("release_json", type=Path)
    args = parser.parse_args()
    release = json.loads(args.release_json.read_text())
    package = Path(release["validation_package"])
    smoke = package.parent / "consumer"
    sources = smoke / "Sources/CoreBinarySmoke"
    (sources / "include").mkdir(parents=True, exist_ok=True)
    (sources / "include/CoreBinarySmoke.h").write_text(
        '#import <Foundation/Foundation.h>\n'
        'FOUNDATION_EXPORT id OxCoreBinarySmokeManager(void);\n'
        'FOUNDATION_EXPORT NSInteger OxCoreBinarySmokeGameLevel(void);\n'
        'FOUNDATION_EXPORT NSString *OxCoreBinarySmokeLocalizedString(void);\n')
    (sources / "CoreBinarySmoke.m").write_text(
        '#import "CoreBinarySmoke.h"\n'
        '@import OxSdkCore;\n'
        '#import <OxSdkCore/OxPreferenceManager.h>\n'
        '#import <OxSdkCore/OxResBundleUtil.h>\n'
        'id OxCoreBinarySmokeManager(void) { return [OxAdSdkManager sharedInstance]; }\n'
        'NSInteger OxCoreBinarySmokeGameLevel(void) { return [OxPreferenceManager shared].gameLevel; }\n'
        'NSString *OxCoreBinarySmokeLocalizedString(void) {\n'
        '    return [OxResBundleUtil localizedString:@"ox_accept"];\n}\n')
    (smoke / "Package.swift").write_text(f'''// swift-tools-version: 5.9
import PackageDescription
let package = Package(
    name: "OxCoreBinarySmoke",
    platforms: [.iOS(.v15)],
    products: [.library(name: "CoreBinarySmoke", type: .dynamic, targets: ["CoreBinarySmoke"])],
    dependencies: [.package(path: "{package}")],
    targets: [.target(
        name: "CoreBinarySmoke",
        dependencies: [.product(name: "OxSdkCore", package: "validation")],
        // Only the temporary host uses this flag; the distributed SDK avoids unsafeFlags.
        linkerSettings: [.unsafeFlags(["-ObjC"])]
    )]
)
''')
    if (package / "Package.resolved").exists():
        shutil.copy2(package / "Package.resolved", smoke / "Package.resolved")
    for name, destination in [("simulator", "generic/platform=iOS Simulator"),
                              ("device", "generic/platform=iOS")]:
        log = smoke / (name + ".log")
        with log.open("w") as stream:
            result = subprocess.run([
                "xcodebuild", "-scheme", "OxCoreBinarySmoke",
                "-destination", destination,
                "-derivedDataPath", str(smoke / ("build-" + name)),
                "-clonedSourcePackagesDirPath", release["package_cache"],
                "-disableAutomaticPackageResolution", "CODE_SIGNING_ALLOWED=NO", "build"
            ], cwd=smoke, stdout=stream, stderr=subprocess.STDOUT)
        if result.returncode:
            print("\n".join(log.read_text(errors="replace").splitlines()[-50:]))
            raise SystemExit(f"{name} failed; log: {log}")
        print(f"{name}: import and link passed; log: {log}", flush=True)
    print("Remote GitHub URL download and App runtime tests remain separate release checks.")


if __name__ == "__main__":
    main()
