//
//  SvgToBezier.h
//
//  Created by Martin Haywood on 5/9/11.
//  Attribution-ShareAlike 3.0 Unported (CC BY-SA 3.0) license 2011 Ponderwell.
//
//  Cleaned up by Bob Monaghan - Glue Tools LLC 6 November 2011
//

#ifdef TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#else
#import <Cocoa/Cocoa.h>
#endif

@interface SvgToBezier : NSObject {
	@private
	CGRect			viewBox;
	float			pathScale;
#ifdef TARGET_OS_IPHONE
	UIBezierPath    *bezier;
#else
	NSBezierPath    *bezier;
#endif
	CGPoint			lastPoint;
	CGPoint			lastControlPoint;
	BOOL			validLastControlPoint;
	NSCharacterSet  *separatorSet;
	NSCharacterSet  *commandSet;
    
    NSMutableArray  *tokens;
}
#ifdef TARGET_OS_IPHONE
@property(nonatomic, readonly) UIBezierPath *bezier;
#else
@property(nonatomic, readonly) NSBezierPath *bezier;
#endif

- (id)initFromSVGPathNodeDAttr:(NSString *)attr rect:(CGRect)rect;

- (void)dealloc;

@end
