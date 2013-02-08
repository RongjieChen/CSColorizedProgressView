//
//  CSColorizedProgressView.h
//  CSColorizedProgressView
//
//  Created by Charles Scalesse on 2/7/13.
//  Copyright (c) 2013 Charles Scalesse. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    CSColorizedProgressViewDirectionBottomToTop,
    CSColorizedProgressViewDirectionTopToBottom,
    CSColorizedProgressViewDirectionLeftToRight,
    CSColorizedProgressViewDirectionRightToLeft
} CSColorizedProgressViewDirection;

typedef void (^CSColorizedCompletionBlock)(CGFloat);

@interface CSColorizedProgressView : UIView

// The full-color image
@property (strong, nonatomic) UIImage *image;

// From 0.0 to 1.0
@property (assign, nonatomic) CGFloat progress;

// Default is bottom to top
@property (assign, nonatomic) CSColorizedProgressViewDirection direction;

// The duration of the progress bar animation, in seconds, to go from 0% to 100% uninterrupted.
// The update animation speed is based on this value. Default is 1 second.
@property (assign, nonatomic) CGFloat totalAnimationDuration;

// When animating, there is a delay between when the target progress is set and
// when the actual progress catches up. This block will be invoked when the progress bar
// has completed animating. It returns the current progress.
@property (nonatomic, copy) CSColorizedCompletionBlock completionBlock;

// Initialize with an image and set the bounds to the image's size
- (id)initWithImage:(UIImage *)image;

// Set the progress with an animation
- (void)setProgress:(CGFloat)progress animated:(BOOL)animated;

// Cancels a running animation
- (void)stopAnimation;

// Adjusts the frame to fit the image
- (void)sizeToFit;

@end
