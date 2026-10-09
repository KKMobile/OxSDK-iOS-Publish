//
//  CipherUtil.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CipherUtil : NSObject

+ (nullable NSString *)decrypt:(NSString *)data;
+ (nullable NSString *)decryptIfNeeded:(NSString *)data;
+ (nullable NSString *)encrypt:(NSString *)data;
+ (BOOL)isEncryptedPayload:(NSString *)data;

@end

NS_ASSUME_NONNULL_END
