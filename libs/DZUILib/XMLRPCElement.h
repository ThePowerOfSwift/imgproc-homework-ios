//
//  XMLRPCElement.h
//  XMLRPCTest
//
//  Created by iOS앱개발세미나 on 12. 3. 15..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XMLElement.h"

@interface XMLRPCElement : XMLElement
@property (nonatomic, strong) XMLRPCElement *parent;    // override
@property (nonatomic, strong, readonly) id value;
@property (nonatomic) BOOL isFault;
@end
