//
//  NSDate+XYCalendar.h
//  XYCalendarView
//
//  Created by eric on 13-9-23.
//  Copyright (c) 2013年 www.51you.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (XYCalendar)

- (BOOL) isSameDay:(NSDate*)anotherDate;
- (BOOL) isSameDay:(NSDate*)anotherDate timeZone:(NSTimeZone*)timeZone;

@end
