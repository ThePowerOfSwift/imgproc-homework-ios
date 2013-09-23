//
//  XMLSOAPEncoder.h
//  DZUILib
//
//  Created by Simon Kim on 12. 3. 30..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import "XMLEncoder.h"

@interface XMLSOAPEncoder : XMLEncoder
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *password;

- (id) initWithUsername:(NSString *) username password:(NSString *)password;
- (NSURLRequest *)requestWithURL:(NSURL *) url 
                          method:(NSString *)method
                      parameters:(NSArray *)parameters;
- (NSURLRequest *)requestWithURL:(NSURL *) url
                          method:(NSString *)method
                      parameters:(NSArray *)parameters
                       useStream:(BOOL) useStream;

@end
