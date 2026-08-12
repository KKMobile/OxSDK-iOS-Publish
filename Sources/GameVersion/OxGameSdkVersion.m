#import "OxGameSdkVersion.h"

#ifndef OX_GAME_SDK_VERSION
#define OX_GAME_SDK_VERSION "Unknown"
#endif

@implementation OxGameSdkVersion

+ (NSString *)version {
    return @OX_GAME_SDK_VERSION;
}

@end
