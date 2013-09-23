//
//  XMLRPCEncoder.h
//  XMLRPCTest
//
//  Created by iOS앱개발세미나 on 12. 3. 15..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XMLRPCEncoder : NSObject

- (NSURLRequest *)requestWithURL:(NSURL *) url 
                                 method:(NSString *)method
                             parameters:(NSArray *)parameters; 

@end
