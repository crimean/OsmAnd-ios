//
//  OAMapViewController.h
//  OsmAnd
//
//  Created by Alexey Pelykh on 7/18/13.
//  Copyright (c) 2013 OsmAnd. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "OACommonTypes.h"
#import "OAMapRendererViewProtocol.h"
#import "OAObservable.h"
#import <Reachability.h>
#import "OAAppSettings.h"

#define kNotificationSetTargetPoint @"kNotificationSetTargetPoint"
#define kNotificationSetTargetPoint @"kNotificationLayersConfigurationChanged"

#if defined(OSMAND_IOS_DEV)
typedef NS_ENUM(NSInteger, OAVisualMetricsMode)
{
    OAVisualMetricsModeOff = 0,
    OAVisualMetricsModeBinaryMapData,
    OAVisualMetricsModeBinaryMapPrimitives,
    OAVisualMetricsModeBinaryMapRasterize
};
#endif // defined(OSMAND_IOS_DEV)

@interface OAMapViewController : UIViewController <UIGestureRecognizerDelegate>

@property(weak, readonly) id<OAMapRendererViewProtocol> mapRendererView;
@property(readonly) OAObservable* stateObservable;
@property(readonly) OAObservable* settingsObservable;

@property(readonly) OAObservable* azimuthObservable;
- (void)animatedAlignAzimuthToNorth;

@property(readonly) OAObservable* zoomObservable;
@property(readonly) OAObservable* mapObservable;
- (BOOL)canZoomIn;
- (void)animatedZoomIn;
- (BOOL)canZoomOut;
- (void)animatedZoomOut;

- (void)goToPosition:(Point31)position31
            animated:(BOOL)animated;
- (void)goToPosition:(Point31)position31
             andZoom:(CGFloat)zoom
            animated:(BOOL)animated;
-(float)calculateMapRuler;

@property(readonly) CGFloat displayDensityFactor;

@property(readonly) OAObservable* framePreparedObservable;

#if defined(OSMAND_IOS_DEV)
@property(nonatomic) BOOL hideStaticSymbols;
@property(nonatomic) OAVisualMetricsMode visualMetricsMode;

@property(nonatomic) BOOL forceDisplayDensityFactor;
@property(nonatomic) CGFloat forcedDisplayDensityFactor;
#endif // defined(OSMAND_IOS_DEV)

@end
