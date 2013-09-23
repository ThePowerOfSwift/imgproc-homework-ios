//
//  DZWebServiceAccessCredential.h
//  DZUILib
//
//  Created by Simon Kim on 12. 4. 9..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DZWebServiceAccessCredential : NSObject
@property (nonatomic, strong) NSURL *url;
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *authKey;
@property (nonatomic, strong) NSString *deviceID;

- (id) initWithURL:(NSURL *) url username:(NSString *) username password:(NSString *) password authKey:(NSString *) authKey deviceID:(NSString *) deviceID;

@end
