//
//  DIPViewController.m
//  ImageProcessing
//
//  Created by Simon Kim on 13. 9. 10..
//  Copyright (c) 2013년 DZPub.com. All rights reserved.
//

#import "DIPViewController.h"
#import "DZUIImagePickerUtility.h"
#import "DZUIAlertUtility.h"
#import "DIPMenuViewController.h"
#import "ImageProcessing.h"
#import <CommonCrypto/CommonDigest.h>


@interface DIPViewController () <DIPMenuViewControllerDelegate>
@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (weak, nonatomic) IBOutlet UILabel *labelContrast;
@property (weak, nonatomic) IBOutlet UIImageView *imageViewHistogram;
@property (weak, nonatomic) IBOutlet UILabel *labelHistogramSummary;
@property (weak, nonatomic) IBOutlet UILabel *labelHistory;
@property (weak, nonatomic) IBOutlet UIButton *buttonClearHistory;
@property (nonatomic, readonly) NSMutableArray *imageHistory;
@property (nonatomic, readonly) NSMutableArray *hashHistory;
@property (nonatomic) NSUInteger currentHistoryIndex;
@property (nonatomic) NSUInteger currentMeasure;
@end

@implementation DIPViewController
@synthesize imageHistory = _imageHistory;
@synthesize hashHistory = _hashHistory;

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.navigationController.toolbarHidden = NO;
    self.activityIndicator.hidden = YES;
    [self showHistory:NO];
    self.currentHistoryIndex = NSNotFound;

    self.imageView.userInteractionEnabled = YES;
    UITapGestureRecognizer *tapRec = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(gestureTap:)];
    [self.imageView addGestureRecognizer:tapRec];
    
    UISwipeGestureRecognizer *swipeRec = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(gestureSwipe:)];
    swipeRec.direction = UISwipeGestureRecognizerDirectionLeft;
    [self.imageView addGestureRecognizer:swipeRec];
    
    swipeRec = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(gestureSwipe:)];
    swipeRec.direction = UISwipeGestureRecognizerDirectionRight;
    [self.imageView addGestureRecognizer:swipeRec];

}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Properties
- (NSMutableArray *) imageHistory
{
    if ( _imageHistory == nil) {
        _imageHistory = [NSMutableArray array];
    }
    return _imageHistory;
}

- (NSMutableArray *) hashHistory
{
    if ( _hashHistory == nil ) {
        _hashHistory = [NSMutableArray array];
    }
    return _hashHistory;
}

#pragma mark - Internal Methods

+ (NSString*) hashMD5Data:(NSData *) data
{
    unsigned char md5Buffer[CC_MD5_DIGEST_LENGTH];
    const char *ptr = data.bytes;
    
    
    CC_MD5(ptr, data.length, md5Buffer);
    
    // Convert MD5 value in the buffer to NSString of hex values
    NSMutableString *output = [NSMutableString stringWithCapacity:CC_MD5_DIGEST_LENGTH * 2];
    for(int i = 0; i < CC_MD5_DIGEST_LENGTH; i++)
        [output appendFormat:@"%02x",md5Buffer[i]];
    
    return output;
}

- (UIImage *) imageAtHistoryIndex:(NSUInteger) index
{
    NSData *data = self.imageHistory[index];
    return [UIImage imageWithData:data];
}

- (void) addImageHistory:(UIImage *) image
{
    NSData *imageData = UIImagePNGRepresentation(image);
    NSString *hash = [[self class] hashMD5Data:imageData];
    NSUInteger index = [[self hashHistory] indexOfObject:hash];
    if ( index == NSNotFound ) {
        [self.imageHistory addObject:imageData];
        [self.hashHistory addObject:hash];
        index = self.imageHistory.count - 1;
    } else {
        NSLog(@"Already in history[%d], hash:%@", index, hash);
    }
    self.currentHistoryIndex = index;
    self.labelHistory.text = [NSString stringWithFormat:@"%d/%d", index + 1, self.imageHistory.count];
}

- (void) showHistory:(BOOL) show
{
    if ( show ) {
        self.labelHistory.hidden = NO;
        self.labelHistory.alpha = 0;
        self.buttonClearHistory.alpha = 0;
        [UIView animateWithDuration:0.3 animations:^{
            self.labelHistory.alpha = 1;
            self.buttonClearHistory.alpha = 1;
        } completion:^(BOOL finished) {
            self.buttonClearHistory.userInteractionEnabled = YES;
        }];
    } else {
        [UIView animateWithDuration:0.3 animations:^{
            self.labelHistory.alpha = 0;
            self.buttonClearHistory.alpha = 0;
        } completion:^(BOOL finished) {
            self.buttonClearHistory.userInteractionEnabled = NO;
            self.labelHistory.hidden = YES;
        }];
    }
}

- (BOOL) historyVisible
{
    return self.labelHistory.hidden == NO;
}



void drawHistogram(CGContextRef ctx, int *pdf, CGRect rect, int max)
{
    
    CGContextFillRect(ctx, rect);
    for( int i = 0; i < 256; i++) {
        CGFloat y = (pdf[i] * rect.size.height) / max;
        y = (rect.origin.y + rect.size.height - y);
        
        CGContextMoveToPoint(ctx, rect.origin.x + i, rect.origin.y + rect.size.height);
        CGContextAddLineToPoint(ctx, rect.origin.x + i, y);
        CGContextStrokePath(ctx);
    }
}

- (UIImage *) imageWithHistogram:(int *) histogram max:(NSUInteger) max min:(NSUInteger) min
{
    UIImage *image = nil;
    CGSize size = CGSizeMake(512, 200);
    UIGraphicsBeginImageContext(size);
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    
    // Histogram (PDF) Graph
    CGContextSetFillColorWithColor(ctx, [UIColor blackColor].CGColor);
    CGContextSetStrokeColorWithColor(ctx, [UIColor whiteColor].CGColor);
    drawHistogram(ctx, histogram, CGRectMake(0, 0, size.width/2, size.height), max);
    
    // CDF: Cumulative Distribution Function Graph
    int cdf[256];
    cdf[0] = histogram[0];
    for( int i = 1; i < 256; i++) {
        cdf[i] = cdf[i-1] + histogram[i];
    }
    CGContextSetFillColorWithColor(ctx, [UIColor blueColor].CGColor);
    CGContextSetStrokeColorWithColor(ctx, [UIColor whiteColor].CGColor);
    drawHistogram(ctx, cdf, CGRectMake(size.width/2, 0, size.width/2, size.height), cdf[255]);
    
    image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}

- (void) setMainImage:(UIImage *) image
{
    self.imageView.image = image;
    self.currentMeasure = [ImageProcessing measureContrast:image];
    self.labelContrast.text = [NSString stringWithFormat:@"%d", self.currentMeasure];
    
    int histogram[256];
    int max = 0, min = 0;
    [ImageProcessing measureImage:image histogram:histogram];
    NSLog(@"%d", histogram[0]);
    for( int i = 0; i < 256; i++) {
        max = MAX(histogram[i], max);
        min = MIN(histogram[i], min);
    }
    self.labelHistogramSummary.text = [NSString stringWithFormat:@"Max:%d Min:%d", max, min];
    self.imageViewHistogram.image = [self imageWithHistogram:histogram max:max min:min];
    [self showHistory:YES];
    
    [self addImageHistory:image];
}

#pragma mark - Actions

- (IBAction)actionCamera:(id)sender {
    
    if ( [UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]) {
        [DZUIImagePickerUtility imagePickerUtilityWithImagePickerReadyBlock:^(UIImagePickerController *picker) {
            //
            picker.sourceType = UIImagePickerControllerSourceTypeCamera;
            [self presentViewController:picker animated:YES completion:^{
                //
            }];
        } imagePickedBlock:^(UIImage *image) {
            //
            [self dismissViewControllerAnimated:YES completion:^{
                [self setMainImage:[ImageProcessing grayscale:image]];
            }];
        } cancelledBlock:^{
            [self dismissViewControllerAnimated:YES
                                     completion:^{
                                         //
                                     }];
        }];
    } else {
        [DZUIAlertUtility alertWithMessage:@"Camera is not available" title:@"Information"];
    }
}
- (IBAction)actionPhotos:(id)sender {
    if ( [UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypePhotoLibrary]) {
        [DZUIImagePickerUtility imagePickerUtilityWithImagePickerReadyBlock:^(UIImagePickerController *picker) {
            //
            picker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
            [self presentViewController:picker animated:YES completion:^{
                //
            }];
        } imagePickedBlock:^(UIImage *image) {
            //
            [self dismissViewControllerAnimated:YES completion:^{
                NSLog(@"self.view:%@", NSStringFromCGRect(self.view.frame));
                NSLog(@"self.imageView:%@", NSStringFromCGRect(self.imageView.frame));
                [self setMainImage:[ImageProcessing grayscale:image]];
            }];
        } cancelledBlock:^{
            [self dismissViewControllerAnimated:YES
                                     completion:^{
                                         //
                                     }];
        }];
    }
}

- (IBAction)actionClearHistory:(id)sender {
    self.currentHistoryIndex = NSNotFound;
    [self.imageHistory removeAllObjects];
    [self.hashHistory removeAllObjects];
    self.imageView.image = nil;
    self.labelHistory.text = @"";
    [self showHistory:NO];
}

#pragma mark - Storyboard
- (void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ( [segue.identifier isEqualToString:@"push_menu"]) {
        DIPMenuViewController *vc = [segue destinationViewController];
        vc.delegate = self;
    }
}

- (void) doAutoFocus
{
    NSUInteger count = self.imageHistory.count;
    int __block max = 0;
    NSUInteger __block indexAtMax = NSNotFound;

    self.activityIndicator.hidden = NO;
    [self.activityIndicator startAnimating];
    for( int i = 0; i < count; i++) {
        [[NSOperationQueue mainQueue] addOperationWithBlock:^{
            UIImage * image = [self imageAtHistoryIndex:i];
            [self setMainImage:image];
            max = MAX(max, self.currentMeasure);
            if ( max == self.currentMeasure) {
                indexAtMax = i;
            }
            if ( i == count -1 ) {
                NSLog(@"max:%d", max);
                [self setMainImage:[self imageAtHistoryIndex:indexAtMax]];
                self.activityIndicator.hidden = YES;
                [self.activityIndicator stopAnimating];
                
                NSString *message = [NSString stringWithFormat:@"Found image with max. contrast:%d", max];
                [DZUIAlertUtility alertWithMessage:message title:@"Done" forDuration:3];
            }
        }];
    }
}

#pragma mark - DIPMenuViewControllerDelegate
- (void) dipMenu:(DIPMenuViewController *) menu didSelect:(DIPMenuItem) menuItem
{
    [self.navigationController popViewControllerAnimated:YES];
    
    [[NSOperationQueue mainQueue] addOperationWithBlock:^{
        //
    switch (menuItem) {
        case DIPMenuItemAutoContrast:
        {
            dispatch_async(dispatch_get_main_queue(), ^{
                self.activityIndicator.hidden = NO;
                [self.activityIndicator startAnimating];
                [self setMainImage:[ImageProcessing histogramEqualization:self.imageView.image]];
                [self.activityIndicator stopAnimating];
                self.activityIndicator.hidden = YES;
            });
            break;
        }
        case DIPMenuItemFocusMeasure:
        {
            if (self.imageHistory.count > 1) {
                [self doAutoFocus];
            } else {
                [DZUIAlertUtility alertWithMessage:@"Load more 2 or more images" title:@"Information"];
            }
            break;
        }
        default:
            break;
    }
    }];
    
}

#pragma mark - Gesture Recognizer
- (void) gestureTap:(UITapGestureRecognizer *) sender
{
    [self showHistory:![self historyVisible]];
}

- (void) gestureSwipe:(UISwipeGestureRecognizer *) sender
{
    if ( sender.direction == UISwipeGestureRecognizerDirectionRight ) {
        // backward
        if (self.currentHistoryIndex > 0 && self.imageHistory.count > 0 ) {
            UIImage *image = [self imageAtHistoryIndex:self.currentHistoryIndex-1];
            [self setMainImage:image];
        }
    } else if ( sender.direction == UISwipeGestureRecognizerDirectionLeft ) {
        // forward
        if ( self.imageHistory.count > 0 && self.currentHistoryIndex < self.imageHistory.count - 1) {
            [self setMainImage:[self imageAtHistoryIndex:self.currentHistoryIndex+1]];
        }
    }
}
@end
