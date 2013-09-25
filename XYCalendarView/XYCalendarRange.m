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
    if (date == nil) {
        [self resetCalendarRange];
        return;
    }
    switch (_rangeState) {
        case CalendarRangeStateNormal:
        case CalendarRangeStateBoth:
        case CalendarRangeStateWhole:
            _startDay = [date copy];
            _rangeState = CalendarRangeStateSingle;
            break;
        case CalendarRangeStateSingle:
            if ([_startDay isSameDay:date]) {
                _endDay = [date copy];
                _rangeState = CalendarRangeStateBoth;
            } else {
                _endDay = [[_startDay laterDate:date] copy];
                _startDay = [[_startDay earlierDate:date] copy];
                _rangeState = CalendarRangeStateWhole;
            }
            break;
        
        default:
            break;
    }
}

- (BOOL)containsDate:(NSDate *)date
{
    
    BOOL _start = [_startDay isSameDay:date];
    BOOL _end = [_endDay isSameDay:date];
    BOOL _inRange = NO;
    switch (_rangeState) {
        case CalendarRangeStateSingle:
        case CalendarRangeStateBoth:
            _inRange = _start;
            break;
        case CalendarRangeStateWhole:
            if (_start || _end || ([_startDay compare:date] == NSOrderedAscending && [_endDay compare:date] == NSOrderedDescending) ) {
                _inRange = YES;
            }
        default:
            break;
    }
    return _inRange;
}
@end