//
//  XYCalendarRange.m
//  XYCalendarView
//
//  Created by eric on 13-9-23.
//  Copyright (c) 2013年 www.51you.com. All rights reserved.
//

#import "XYCalendarRange.h"
#import "NSDate+XYCalendar.h"

@implementation XYCalendarRange

- (id)init
{
    if (self = [super init]) {
        [self resetCalendarRange];
    }
    return self;
}

- (void)resetCalendarRange
{
    _rangeState = CalendarRangeStateNormal;
    _startDay = nil;
    _endDay = nil;
}

- (void)updateWithDate:(NSDate *)date
{
    switch (_rangeState) {
        case CalendarRangeStateNormal:
        case CalendarRangeStateBoth:
        case CalendarRangeStateWhole:
            _startDay = date;
            _rangeState = CalendarRangeStateSingle;
            break;
        case CalendarRangeStateSingle:
            if ([_startDay isSameDay:date]) {
                _endDay = date;
                _rangeState = CalendarRangeStateBoth;
            } else {
                _endDay = [_startDay laterDate:date];
                _startDay = [_startDay earlierDate:date];
                _rangeState = CalendarRangeStateWhole;
            }
            break;
        
        default:
            break;
    }
}
@end