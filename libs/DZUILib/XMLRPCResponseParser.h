//
//  XMLRPCResponseParser.h
//  XMLRPCTest
//
//  Created by iOS앱개발세미나 on 12. 3. 15..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XMLRPCElement.h"

@interface XMLRPCResponseParser : NSObject
@property (nonatomic, readonly) NSError *xmlParserError;
@property (nonatomic, readonly) NSString *parsedXMLText;
@property (nonatomic, readonly) XMLRPCElement *parsedElement;
- (BOOL) parseResponseData:(NSData *) data;
@end
