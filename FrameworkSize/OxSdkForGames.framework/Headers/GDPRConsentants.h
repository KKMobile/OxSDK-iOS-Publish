//
//  GDPRConsentants.h
//  OxSdkCore
//
//  Created by Mavl_2023_100272 on 2023/7/28.
//  Copyright © 2023 耿志向. All rights reserved.
//
static NSString* const EVENT_CONSENT_INIT = @"consent_init";
static NSString* const EVENT_CONSENT_INIT_FINISH = @"consent_init_finish";
static NSString* const EVENT_CONSENT_SHOW_DIALOG = @"consent_show_dialog";
static NSString* const EVENT_CONSENT_DIALOG_DISMISSED = @"consent_dialog_dismissed";
static NSString* const EVENT_CONSENT_ERROR = @"consent_error";

static NSString* const PARAM_IS_SUBJECT_TO_GDPR = @"subject_to_gdpr";
static NSString* const PARAM_PLATFORM = @"platform";
static NSString* const PARAM_IS_FORCE_TO_SHOW = @"force_to_show";
static NSString* const PARAM_WILL_SHOW = @"will_show";
static NSString* const PARAM_ERROR_MSG = @"error_msg";
static NSString* const PARAM_GOOGLE_CONSET_STATUS = @"google_consent_status";
static NSString* const PARAM_SFBX_ANY_ALLOWED = @"sfbx_any_allowed";
static NSString* const PARAM_SFBX_ALL_ALLOWED = @"sfbx_all_allowed";

static NSString* const VALUE_GOOGLE = @"google";
static NSString* const VALUE_SFBX = @"sfbx";
static NSString* const VALUE_MAX = @"max";
