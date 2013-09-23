//
//  DZWebServiceAPI.h
//  DZUILib
//
//  Created by Simon Kim on 12. 3. 30..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DZWebServiceAccessCredential.h"
#import "DZWebServiceStyleSheetTemplate.h"

typedef enum {
    DZWebServicePostStatusTypeUnknown,
    DZWebServicePostStatusTypeDraft,
    DZWebServicePostStatusTypePrivate,
    DZWebServicePostStatusTypePending,
    DZWebServicePostStatusTypePublished
} DZWebServicePostStatusType;

typedef enum {
    DZWebServiceCapabilityNone                  = 0,
    DZWebServiceCapabilityAnonymousUse          = 0x01,
    DZWebServiceCapabilitySignup                = 0x02,
    DZWebServiceCapabilityCategories            = 0x04,
    DZWebServiceCapabilityTags                  = 0x08,
    DZWebServiceCapabilityPostStatus            = 0x10,
    DZWebServiceCapabilityStyleSheetTemplates   = 0x20
} DZWebServiceCapability;

#define kDZWebServicePostingUserInfoKeyPostStatus    @"postStatus"  // NSNumber
#define kDZWebServicePostingUserInfoKeyCategories    @"categories"  // NSArray of NSString
#define kDZWebServicePostingUserInfoKeyTags          @"tags"        // NSArray of NSString
#define kDZWebServicePostingUserInfoKeyStyleSheetURL @"styleSheetURL"   // NSString
#define kDZWebServicePostingUserInfoKeyNoteThumbnailURL     @"noteThumbnailURL" // NSString
#define kDZWebServicePostingUserInfoKeyDescription  @"description"  // NSString
#define kDZWebServicePostingUserInfoKeyDeviceID  @"deviceId"  // NSString
#define kDZWebServicePostingUserInfoKeyShareTwitter  @"twitterYn"  // NSString
#define kDZWebServicePostingUserInfoKeyShareFacebook  @"facebookYn"  // NSString
#define kDZWebServicePostingUserInfoKeyFacebookAccessToken  @"fbToken"  // NSString

#define kWebServiceDomain    @"Web Service"
#define kWebServiceErrorUnknown    -1
#define kWebServiceErrorCancelled    -2
#define kWebServiceErrorInvalidArguments -3
#define kWebServiceErrorInvalidResponse   -4


typedef void (^DZWSRequestCompletionHandler)(id result, NSError *error);

@interface DZWebServiceAPI : NSObject
@property (nonatomic, readonly) NSString *errorMessage;
@property (nonatomic, readonly) DZWebServiceAccessCredential *credential;

/// Initialization
- (id) initWithCredential:(DZWebServiceAccessCredential *) credential;

// Sign-up
// Return: authKey
- (NSString *) createAccount:(NSString *) username
                    password:(NSString *) password
                    deviceID:(NSString *) deviceID
                 displayName:(NSString *) displayName;

// Login
// Return: authKey
- (NSString *) loginWith:(NSString *) username
                password:(NSString *) password
                deviceID:(NSString *) deviceID;

- (BOOL) validateLogin;
/// Once validateLogin returns YES, it's guaranteed serverName is available
- (NSString *) serverName;

// Uploading attachment
- (NSURL *) uploadBinaryFromURL:(NSURL *) binaryURL mimeType:(NSString *) mimeType;
- (NSURL *) uploadImageLocalCacheURL:(NSURL *) jpegURL;

// Posting
- (NSURL *) uploadPostLocalCacheURL:(NSURL *) postURL withSubject:(NSString *) subject introImgURL:(NSString *) string;
- (NSURL *) uploadPostLocalCacheURL:(NSURL *) postURL withSubject:(NSString *) subject introImgURL:(NSString *) string
                         postStatus:(DZWebServicePostStatusType) postStatus
                         categories:(NSArray *) categories
                               tags:(NSArray *) tags; // of NSString
- (NSURL *) uploadPostLocalCacheURL:(NSURL *) postURL withSubject:(NSString *) subject userInfo:(NSDictionary *)userInfo;
- (NSURL *) uploadPostText:(NSString *) text withSubject:(NSString *) subject userInfo:(NSDictionary *)userInfo;

/**
 * extract a value for 'key' from excuteMethod result
 * Return:
 *      key != nil, NSString value
 *      key == nil, NSDictionary contains whole value tree
 */
- (id) getValueFromResult:(id) result forKey:(NSString *) key;
- (id) executeMethod:(NSString *)method withParameters:(NSArray *) parameters;
- (NSArray *) queryCategories;  // of NSDictionary { key: categoryId, value:categoryName }
- (NSURL *) feedURLPage:(NSUInteger) page category:(id) categoryID;
- (DZWebServiceCapability) capabilities;
/// Return: Array of DZWebServiceStyleSheetTemplate
- (void) queryTemplatesWithCompletion:(DZWSRequestCompletionHandler) completion;
/*
 newDocument.themeStyleSheetURLString = document.themeStyleSheetURLString;
 newDocument.blogCategory = document.blogCategory;
 newDocument.blogPostStatus = document.blogPostStatus;
*/ 
+ (NSDictionary *) userInfoWithStyleSheetURLString:(NSString *) styleSheetURLString
                                      thumbnailURL:(NSString *) thumbnailURL
                                        postStatus:(DZWebServicePostStatusType) postStatus
                                        categories:(NSArray *)categories
                                              tags:(NSArray *) tags
                                       description:(NSString *) description;

- (NSError *) errorWithCode:(NSUInteger) code;

/*
 * Asynchronous API
 */
- (id) executeAsyncMethod:(NSString *)method withParameters:(NSArray *) parameters completion:(DZWSRequestCompletionHandler) completion;

- (id) uploadImageAtLocalURL:(NSURL *) imageURL completion:(DZWSRequestCompletionHandler) completion;
- (id) uploadPostText:(NSString *) text withSubject:(NSString *) subject userInfo:(NSDictionary *)userInfo completion:(DZWSRequestCompletionHandler) completion;
- (id) uploadPostAtLocalURL:(NSURL *) url withSubject:(NSString *) subject userInfo:(NSDictionary *)userInfo completion:(DZWSRequestCompletionHandler) completion;
- (void) cancelRequest:(id) tracker;


@end
