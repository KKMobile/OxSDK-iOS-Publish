//
//  PrivacyPopupView.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/19.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^TapClick)(void);
typedef void (^AcceptClick)(void);
typedef void (^MoreClick)(void);

@interface PrivacyPopupView : UIView

@property (nonatomic, copy) TapClick tapClick;
@property (nonatomic, copy) AcceptClick acceptClick;
@property (nonatomic, copy) MoreClick moreClick;
@property (nonatomic, strong) UIView* blackBgV;
@property (nonatomic, strong) UIView* alertV;

- (instancetype)initWithAcceptClicked:(AcceptClick)acceptClick
                moreClick:(MoreClick)moreClick tapClick:(TapClick)tapClick;
/**
*  AlertView显示
*/
- (void)show;

@end

NS_ASSUME_NONNULL_END

