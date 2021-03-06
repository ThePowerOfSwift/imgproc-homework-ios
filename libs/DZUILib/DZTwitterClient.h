//
//  TwitterClientTests.h
//  TwitterClient
//
//  Created by Simon Kim on 12. 6. 1..
//  Copyright (c) 2012년 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Accounts/Accounts.h>

@interface DZTwitterClient : NSObject
- (void) queryAccountsWithCompletion:(void (^)(BOOL granted, NSArray *accounts)) completion;
- (void) updateProfileWithImageURL:(NSURL *) imageURL account:(ACAccount *) account completed:(void (^)(BOOL succeed, NSDictionary *userInfo)) completed;
- (void) updateProfileWithImageData:(NSData *) imageData account:(ACAccount *) account completed:(void (^)(BOOL succeed, NSDictionary *userInfo)) completed;

@end
