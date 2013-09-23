//
//  DZWebPostItem.h
//  DZUILib
//
//  Created by Simon Kim on 12. 4. 7..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DZWebFeedItem.h"

@interface DZWebPostItem : NSObject
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *date;
@property (nonatomic, strong) NSURL *profileImageURL;
@property (nonatomic, strong) NSURL *thumbnailImageURL;
@property (nonatomic, strong) NSString *author;
@property (nonatomic) NSUInteger numComments;
@property (nonatomic, strong) NSURL *postURL;
@property (nonatomic, strong) NSURL *commentsFeedURL;
@property (nonatomic, strong) id cookie;        // meta data can be used to identify the post itself or...
                                                // could be DZWebFeedItem

- (DZWebPostItem *) convertFromFeedItem:(DZWebFeedItem *) feedItem;
+ (DZWebPostItem *) postItemFromFeedItem:(DZWebFeedItem *) feedItem;
@end
