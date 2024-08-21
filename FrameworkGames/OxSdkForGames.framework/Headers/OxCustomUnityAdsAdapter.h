//
//  MAUnityMediationAdapter.h
//  AppLovinSDK
//
//  Created by Santosh Bagadi on 9/2/18.
//  Copyright © 2022 AppLovin Corporation. All rights reserved.
//

#import <AppLovinSDK/AppLovinSDK.h>

// Change: game_id  => app_id

@interface OxCustomUnityAdsAdapter : ALMediationAdapter <MASignalProvider, MAInterstitialAdapter, MARewardedAdapter, MAAdViewAdapter>

@end
