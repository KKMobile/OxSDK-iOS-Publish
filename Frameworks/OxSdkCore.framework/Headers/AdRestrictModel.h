//
//  AdRestrictModel.h
//  OxSdkCore
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdRestrictAI : NSObject

@property (nonatomic, copy, nullable) NSString *dm;
@property (nonatomic, assign) long long m;
@property (nonatomic, copy, nullable) NSString *cc;
@property (nonatomic, copy, nullable) NSString *sv;

+ (instancetype)fromDictionary:(NSDictionary *)dict;

@end

@interface AdRestrictLoadRule : NSObject

@property (nonatomic, copy, nullable) NSString *dm;
@property (nonatomic, assign) long long m;
@property (nonatomic, copy, nullable) NSString *cc;
@property (nonatomic, copy, nullable) NSString *sv;
@property (nonatomic, assign) BOOL b;
@property (nonatomic, assign) BOOL i;
@property (nonatomic, assign) BOOL r;
@property (nonatomic, assign) BOOL o;
@property (nonatomic, assign) BOOL n;

+ (instancetype)fromDictionary:(NSDictionary *)dict;

@end

@interface AdRestrictShowRule : NSObject

@property (nonatomic, copy, nullable) NSString *dm;
@property (nonatomic, assign) long long m;
@property (nonatomic, copy, nullable) NSString *cc;
@property (nonatomic, copy, nullable) NSString *sv;
@property (nonatomic, assign) BOOL b;
@property (nonatomic, assign) BOOL i;
@property (nonatomic, assign) BOOL r;
@property (nonatomic, assign) BOOL o;
@property (nonatomic, assign) BOOL n;

+ (instancetype)fromDictionary:(NSDictionary *)dict;

@end

@interface AdRestrictConfig : NSObject

@property (nonatomic, copy, nullable) NSString *n;
@property (nonatomic, assign) long long v;
@property (nonatomic, copy, nullable) NSArray<AdRestrictAI *> *ai;
@property (nonatomic, copy, nullable) NSArray<AdRestrictLoadRule *> *l;
@property (nonatomic, copy, nullable) NSArray<AdRestrictShowRule *> *s;

+ (nullable instancetype)fromJSONString:(NSString *)jsonString;

@end

NS_ASSUME_NONNULL_END
