//
//  ConsentPopupView.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/19.
//


#import <UIKit/UIKit.h>
#import "OxConsentMananger.h"
#import "OxCMPConsentManager.h"

NS_ASSUME_NONNULL_BEGIN

@class ConsentPopupView;

typedef void (^BackClick)(void);
typedef void (^SaveClick)(BOOL isOn);
typedef void (^ChangeConsentStateClick)(BOOL isOn);

@interface ConsentPopupView : UIView

@property (nonatomic, copy) BackClick backClick;
@property (nonatomic, copy) SaveClick saveClick;
@property (nonatomic, copy) ChangeConsentStateClick changeConsentStateClick;
@property (nonatomic, strong) UIView* blackBgV;
@property (nonatomic, strong) UIView* alertV;
@property (nonatomic, assign, readonly) ConsentEntryType entryType;

- (instancetype)initWithEntryType:(ConsentEntryType)entryType backClicked:(BackClick)backClick saveClick:(SaveClick)saveClick changeConsentStateClick:(ChangeConsentStateClick)changeConsentStateClick;
/**
 *  AlertView显示
 */
- (void)show;

@end

NS_ASSUME_NONNULL_END

