//
//  DZWebWordPressAPI.h
//  XMLRPCTest
//
//  Created by Simon Kim on 12. 3. 25..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DZWebServiceAPI.h"
@interface DZWebWordPressAPI : DZWebServiceAPI
@property (nonatomic, strong) NSURL *blogURL;
@property (nonatomic) NSInteger blogID;
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *blogName;

- (id) initWithBlogURL:(NSURL *) url username:(NSString *) username password:(NSString *) password;
- (void) loadSettings;
- (void) saveSettings;

- (NSString *) stringFromPostStatus:(DZWebServicePostStatusType) postStatus;

- (BOOL) isFaultResponse:(id) response;
- (id) executeMethod:(NSString *)method withParameters:(NSArray *) parameters;

// keys: on success
//  file: string
//  type: string
//  url : string
// keys: on fault
//  faultCode: int
//  faultString: string

- (NSDictionary *) uploadImage:(UIImage *) image;
- (NSDictionary *) uploadImageURL:(NSURL *) jpegURL;
- (NSURL *) urlForNewUploadedImage:(UIImage *) image;
- (NSURL *) urlForNewUploadedImageURL:(NSURL *) jpegURL;


// return array of NSDictionary
//                  {faultCode, faultString} or
//                  { title ...}
- (NSArray *) getRecentPostTitlesNumPosts:(NSUInteger) numPosts;
- (NSArray *) getRecentPostsNumPosts:(NSUInteger) numPosts;
- (NSDictionary *) getPost:(NSString *) postID;
- (NSString *) editPostID:(NSString *) postID withText:(NSString *) text withSubject:(NSString *) subject userInfo:(NSDictionary *)userInfo;

// return array of NSDictionary
//                  {faultCode, faultString} 
//                  or NSString: post_id
- (NSArray *) postText:(NSString *) text withSubject:(NSString *) subject;
- (NSArray *) postText:(NSString *) text withSubject:(NSString *) subject
            postStatus:(NSString *) postStatus 
            categories:(NSArray *)categories 
                  tags:(NSArray *) tags 
           extraParams:(NSDictionary *) extraParams;

- (NSString *) newPostIDAfterPostingText:(NSString *) text 
                             withSubject:(NSString *) subject 
                              postStatus:(NSString *) postStatus 
                              categories:(NSArray *) categories
                                    tags:(NSArray *) tags;
- (NSString *) newPostIDAfterPostingText:(NSString *) text withSubject:(NSString *) subject userInfo:(NSDictionary *)userInfo;
- (NSString *) editPostID:(NSString *) postID withText:(NSString *) text withSubject:(NSString *) subject userInfo:(NSDictionary *)userInfo;
- (NSDictionary *) getUserInfo;

// Comments
- (NSString *) newCommentForPostID:(NSString *) postID withContent:(NSString *) content;
- (NSArray *) getCommentsForPostID:(NSString *) postID num:(NSUInteger) number offset:(NSUInteger) offset;

- (BOOL) validateLogin;

+ (DZWebWordPressAPI *) apiWithBlogURL:(NSURL *) url username:(NSString *) username password:(NSString *) password;

@end
