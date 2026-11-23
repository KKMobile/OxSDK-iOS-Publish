#import <Foundation/Foundation.h>
@class OxNativeViewBinder;
@protocol NativeViewBinderAware <NSObject>
- (void)setViewBinder:(OxNativeViewBinder *)binder;
@end
