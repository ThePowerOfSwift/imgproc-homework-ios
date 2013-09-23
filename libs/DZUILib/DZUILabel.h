//
//  DZUILabel.h
//  RakeOrShake_Prototype
//
//  Created by Simon Kim on 09. 07. 02.
//  Copyright 2009 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DZUITextAlignment.h"
// Label2.h
// (c) 2009 Ivan Misuno, www.cuberoom.biz

@interface DZUILabel : UILabel
@property (nonatomic) DZUITextVerticalAlignment verticalAlignment;
@property (nonatomic) NSUInteger textInset;
@end
