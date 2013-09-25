//
//  XYCalendarView.h
//  XYCalendarView
//
//  Created by eric on 13-9-23.
//  Copyright (c) 2013年 www.51you.com. All rights reserved.
//
#import "XYCalendarRange.h"

@protocol XYCalendarDelegate, XYCalendarDataSource;

@interface XYCalendarView : UIView

@property (nonatomic, assign) id<XYCalendarDelegate> delegate;
@property (nonatomic, assign) id<XYCalendarDataSource> dataSource;

- (XYCalendarRange *) rangeSelected;


/** The current month date being displayed.
 @return An `NSDate` object set to the month and year of the current month grid.
 */
- (NSDate*) monthDate;

/** Selects a specific date in the month grid.
 @param date The date that will be highlighed.
 */
- (BOOL) selectDate:(NSDate*)date;

/** Reloads the current month grid. */
- (void) reloadData;

/** Animates the calendar to the next or previous month.
 @param next YES for next month, NO for previous month.
 */
- (void) animateToNextOrPreviousMonth:(BOOL)next;

@end

@protocol XYCalendarDelegate <NSObject>

@optional
- (void) calendarView:(XYCalendarView *)calendarView didSelectRange:(XYCalendarRange *)range;
- (BOOL) calendarView:(XYCalendarView *)calendarView monthShouldChange:(NSDate *)month animated:(BOOL)animated;

/** The calendar will change the current month to grid shown.
 @param monthView The calendar month view.
 @param month The month date.
 @param animated Animation flag
 */
- (void) calendarView:(XYCalendarView *)calendarView monthWillChange:(NSDate *)month animated:(BOOL)animated;

/** The calendar did change the current month to grid shown.
 @param monthView The calendar month view.
 @param month The month date.
 @param animated Animation flag
 */
- (void) calendarView:(XYCalendarView *)calendarView monthDidChange:(NSDate *)month animated:(BOOL)animated;

@end

@protocol XYCalendarDataSource <NSObject>

- (void) calendarView:(XYCalendarView *)calendarView day:(NSDate *)date WithPrompt:(NSString *)prompt;

@end
