//
//  DIPTiePointsView.m
//  ImageProcessing
//
//  Created by Simon Kim on 13. 10. 23..
//  Copyright (c) 2013년 DZPub.com. All rights reserved.
//

#import "DIPTiePointsView.h"

@interface DIPTiePointsView()
@property (nonatomic, strong) NSMutableArray *pointViews;
@end

@implementation DIPTiePointsView

- (void) commonInit
{
    UITapGestureRecognizer *gestureTap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(gestureTap:)];
    [self addGestureRecognizer:gestureTap];
    self.pointViews = [NSMutableArray array];
}

- (void) awakeFromNib
{
    [self commonInit];
}

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self commonInit];
    }
    return self;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

- (NSArray *) tiePointsScaleBySize:(CGSize) size
{
    NSMutableArray *points = [NSMutableArray array];
    CGAffineTransform transform = CGAffineTransformMakeScale(size.width / self.bounds.size.width, size.height / self.bounds.size.height);
    if ( self.pointViews.count > 0 ) {
        for( int i = 0; i < self.pointViews.count; i++) {
            UIView *view = self.pointViews[i];
            CGPoint point = CGPointApplyAffineTransform(view.center, transform);
            [points addObject:[NSValue valueWithCGPoint:point]];
        }
    }
    return [points copy];
}

- (void) removePoints
{
    [self.pointViews enumerateObjectsUsingBlock:^(UIView *view, NSUInteger idx, BOOL *stop) {
        [view removeFromSuperview];
    }];
    [self.pointViews removeAllObjects];
}

- (void) addPoint:(CGPoint) point
{
    UIImageView *view = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"ball"]];
    view.center = point;
    [self addSubview:view];
    [self.pointViews addObject:view];
    
    view.userInteractionEnabled = YES;
    UIPanGestureRecognizer *gesturePan = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(gesturePan:)];
    [view addGestureRecognizer:gesturePan];
}

- (void) addPointsDefault
{
    CGSize size = self.bounds.size;
    [self addPoint:CGPointMake(0, 0)];
    [self addPoint:CGPointMake(size.width, 0)];
    [self addPoint:CGPointMake(0, size.height)];
    [self addPoint:CGPointMake(size.width, size.height)];
}

#pragma mark - Gesture
- (void) gestureTap:(UITapGestureRecognizer *) sender
{

    if ( self.pointViews.count > 0)  {
        [self removePoints];
    } else {
        [self addPointsDefault];
    }
}

- (void) gesturePan:(UIPanGestureRecognizer *) sender
{
    CGPoint translation = [sender translationInView:self];
    CGPoint center = sender.view.center;
    center.x += translation.x;
    center.y += translation.y;
    if ( CGRectContainsPoint(self.bounds, center)) {
        sender.view.center = center;
    }
    [sender setTranslation:CGPointMake(0, 0) inView:self];
}
@end
