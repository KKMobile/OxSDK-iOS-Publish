//
//  PluginInitializerProvider.h
//  OxSdkPluginRegistry
//
//  iOS equivalent of Android PluginInitializerProvider.
//  Each plugin pod registers services in +load via a bootstrap class.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PluginInitializerProvider <NSObject>

+ (void)registerPlugins;

@end

NS_ASSUME_NONNULL_END
