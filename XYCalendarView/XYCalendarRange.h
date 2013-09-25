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

@property (nonatomic, readonly) NSDate *startDay;
@property (nonatomic, readonly) NSDate *endDay;

@property (nonatomic, assign, readonly) CalendarRangeState rangeState;

- (void)updateWithDate:(NSDate *)date;

- (BOOL)containsDate:(NSDate *)date;
@end
