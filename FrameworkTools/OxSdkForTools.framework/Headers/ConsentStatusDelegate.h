//
//  ConsentStatusDelegate.h
//  SwithMediationDemo
//
//  Created by BJMM100001 on 2022/5/19.
//

#ifndef ConsentStatusDelegate_h
#define ConsentStatusDelegate_h

@protocol ConsentStatusDelegate <NSObject>

- (void)onConsentAccepted;

- (void)onConsentRejected;

- (void)onConsentUnknown;

@end

#endif /* ConsentStatusDelegate_h */
