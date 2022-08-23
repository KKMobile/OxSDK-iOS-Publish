//
//  OxKeywordType.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/8/15.
//

#ifndef OxKeywordType_h
#define OxKeywordType_h


#endif /* OxKeywordType_h */

// EventLevel
typedef NS_ENUM(NSInteger, OxKeywordType) {
    KEYWORD_TYPE_NONE = 0,
    KEYWORD_TYPE_CHANNEL = 1,
    KEYWORD_TYPE_CAMPAIGN = 1 << 1,
    KEYWORD_TYPE_USER_GROUP = 1 << 2,
    KEYWORD_TYPE_DEEP_USER = 1 << 3,
    KEYWORD_TYPE_ALL = (1 << 4) - 1
};
