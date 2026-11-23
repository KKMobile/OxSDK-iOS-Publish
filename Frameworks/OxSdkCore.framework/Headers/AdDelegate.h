//
//  AdLoaderDelegate.h
//  AdmobADSdkProj
//
//  Created by Rober on 2021/12/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** 广告业务回调。Loaded 可来自缓存；Displayed/Closed 表示展示生命周期，失败需分别处理加载与展示错误。回调中广告位为 SDK 逻辑广告位，不应作为平台网络 ID 使用。 */
@protocol AdDelegate <NSObject>


/// 已有就绪广告（含可用 BackUp）；缓存命中也可能触发。
- (void)onAdLoaded:(NSString*)adUnitId;

/// 当前加载未能提供可用广告，附带失败原因。
- (void)onAdLoadFailed:(NSString*)adunitId errorInfo:(NSString *)error;

/// 广告网络通知展示/曝光。
- (void)onAdDisplayed:(NSString*)adUnitId;

/// 展示失败；与加载失败分开处理。
- (void)onAdDisplayFailed:(NSString*)adunitId errorInfo:(NSString *)error;

/// 广告被点击。
- (void)onAdClicked:(NSString*)adUnitId;

- (void)onAdOpened:(NSString*)adUnitId;

/// 广告关闭。
- (void)onAdClosed:(NSString*)adUnitId;
@end

NS_ASSUME_NONNULL_END
