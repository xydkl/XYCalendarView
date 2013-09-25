//
//  NSDate+XYCalendar.m
//  XYCalendarView
//
//  Created by eric on 13-9-23.
//  Copyright (c) 2013年 www.51you.com. All rights reserved.
//

#import "NSDate+XYCalendar.h"

@implementation NSDate (XYCalendar)

- (BOOL) isSameDay:(NSDate*)anotherDate{
	return [self isSameDay:anotherDate timeZone:[NSTimeZone defaultTimeZone]];
}
- (BOOL) isSameDay:(NSDate*)anotherDate timeZone:(NSTimeZone*)timeZone{
	NSCalendar* calendar = [NSCalendar currentCalendar];
	calendar.timeZone = timeZone;
	NSDateComponents* components1 = [calendar components:(NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit) fromDate:self];
	NSDateComponents* components2 = [calendar components:(NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit) fromDate:anotherDate];
	return ([components1 year] == [components2 year] && [components1 month] == [components2 month] && [components1 day] == [components2 day]);
}
@end
