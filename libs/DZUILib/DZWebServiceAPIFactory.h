//
//  DZWebServiceAPIFactory.h
//  DZUILib
//
//  Created by Simon Kim on 12. 3. 30..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DZWebServiceAPI.h"

typedef enum {
    DZWebServiceTypeRichNote = 0,
    DZWebServiceTypeWordPressDotCom,
    DZWebServiceTypeWordPress,
    DZWebServiceTypeObjectStore,
} DZWebServiceType;

@interface DZWebServiceAPIFactory : NSObject

+ (DZWebServiceAPI *) webServiceAPIForServiceType:(DZWebServiceType) serviceType 
                                          baseURL:(NSURL *) url 
                                         username:(NSString *)username 
                                         password:(NSString *)password 
                                          authKey:(NSString *)authKey
                                         deviceID:(NSString *)deviceID;
@end
