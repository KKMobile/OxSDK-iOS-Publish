//
//  ConsentPopupView.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/19.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^BackClick)(void);
typedef void (^SaveClick)(BOOL);

@interface ConsentPopupView : UIView

@property (nonatomic, copy) BackClick backClick;
@property (nonatomic, copy) SaveClick saveClick;
@property (nonatomic, strong) UIView* blackBgV;
@property (nonatomic, strong) UIView* alertV;

- (instancetype)initWithBackClicked:(BackClick)backClick
                saveClick:(SaveClick)saveClick;
/**
*  AlertView显示
*/
- (void)show;

@end

NS_ASSUME_NONNULL_END

