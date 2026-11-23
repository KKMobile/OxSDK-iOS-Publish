#import <Foundation/Foundation.h>
@class AdapterConfig;
/// Adapters register local code at +load; remote configuration cannot name executable classes.
@interface OptionalAdapterInitializerRegistry : NSObject
+ (instancetype)sharedInstance;
- (void)registerMediation:(NSString *)mediation initializer:(void (^)(NSDictionary *config))initializer;
- (BOOL)isRegisteredMediation:(NSString *)mediation;
- (void)initializeConfiguredAdapters:(AdapterConfig *)config;
- (void)trackInitializationEnd:(NSString *)mediation isSuccess:(BOOL)isSuccess error:(NSString *)error;
@end
