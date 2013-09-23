//
//  DZWebFeedItem.h
//  SeminarSamples
//
//  Created by Simon Kim on 12. 4. 6..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface DZWebFeedItem : NSObject
@property (nonatomic, strong) NSDictionary *attributes;
@property (nonatomic, strong, readonly) NSMutableDictionary *subElements; // of DZWebFeedItem object values
@property (nonatomic, strong) NSString *text;
@property (nonatomic, readonly) NSString *trimmedText;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSArray *imageURLs;   // of URL


- (id) initWithName:(NSString *) name;
- (DZWebFeedItem *) subElementForKey:(id) key;
- (DZWebFeedItem *) subElementForKey:(id) key createIfNone:(BOOL) createIfNone;
- (NSString *) dateString;  // only for "pubDate" item
+ (DZWebFeedItem *) feedItemWithName:(NSString *)name;
@end
