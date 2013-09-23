//
//  XYCalendarRange.h
//  XYCalendarView
//
//  Created by eric on 13-9-23.
//  Copyright (c) 2013年 www.51you.com. All rights reserved.
//

#import <Foundation/Foundation.h>

//  Define not selected, selected single, select the same date, select different date state
typedef NS_ENUM(NSInteger, CalendarRangeState) {
    CalendarRangeStateNormal,
    CalendarRangeStateSingle,
    CalendarRangeStateBoth,
    CalendarRangeStateWhole
};

@interface XYCalendarRange : NSObject

@property (nonatomic, copy) NSDate *startDay;
@property (nonatomic, copy) NSDate *endDay;

@property (nonatomic, strong, readonly) NSTimeZone *timeZone;
@property (nonatomic, assign, readonly) CalendarRangeState rangeState;

- (id)initWithTimeZone:(NSTimeZone *)timeZone;
- (void)updateWithDate:(NSDate *)date;
- (void)resetCalendarRange;


@end
