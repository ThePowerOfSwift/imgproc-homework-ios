//
//  XMLSOAPResponseParser.h
//  DZUILib
//
//  Created by Simon Kim on 12. 3. 30..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XMLElement.h"

@interface XMLSOAPResponseParser : NSObject
@property (nonatomic, strong) NSString *resultCode;
@property (nonatomic, strong) NSString *resultMsg;
@property (nonatomic, strong) NSString *resultValue;
@property (nonatomic, readonly) XMLElement *parsedElement;

- (BOOL) parseResponseData:(NSData *) data;

@end
