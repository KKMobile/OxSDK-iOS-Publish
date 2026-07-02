#
#  OxSdkPluginRegistry.podspec
#  Public plugin registration API for Ox SDK plugin pods.
#

Pod::Spec.new do |spec|
  spec.name         = "OxSdkPluginRegistry"
  spec.version      = "3.0.0"
  spec.summary      = "Ox SDK plugin registry API."
  spec.description  = <<-DESC
  Header-only plugin registry contracts shared between OxSdkCore and Ox*Plugin pods.
                   DESC
  spec.homepage     = "https://github.com/KKMobile/OxSDK-iOS-Publish.git"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "OxDevelopers" => "tianci5275@gmail.com" }
  spec.platform     = :ios
  spec.ios.deployment_target = "12.0"
  spec.source       = { :git => "https://github.com/KKMobile/OxSDK-iOS-Publish.git", :tag => "plugin-registry-#{spec.version}" }
  spec.source_files = "iOS/OxSDK-Game/OxSdkPluginRegistry/**/*.{h,m}"
  spec.public_header_files = "iOS/OxSDK-Game/OxSdkPluginRegistry/**/*.h"
  spec.requires_arc = true
end
