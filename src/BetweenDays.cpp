/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;

};

struct Date
{
	int da, mo, ye;
};

Date convertToDate(struct node* d)
{
	int z = d->data;
	int day = z * 10 + d->next->data;
	d = d->next->next;
	int y = d->data;
	int m = y * 10 + d->next->data;
	d = d->next->next;
	int x = d->data;
	x = x * 10 + d->next->data;
	x = x * 10 + d->next->next->data;
	int yr = x * 10 + d->next->next->next->data;
	struct Date d1;
	d1.da = day;
	d1.mo = m;
	d1.ye = yr;
	return d1;
}

int DaysInMonth[12] = { 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };

int countLeapYears(Date d)
{
	int years = d.ye;
	if (d.mo <= 2)
		years--;
	return years / 4 - years / 100 + years / 400;
}

int getDifference(Date dt1, Date dt2)
{
	int d1 = dt1.ye * 365 + dt1.da;
	int d2 = dt2.ye * 365 + dt2.da;
	for (int i = 0; i<dt1.mo - 1; i++)
		d1 += DaysInMonth[i];
	d1 += countLeapYears(dt1);
	for (int i = 0; i<dt2.mo - 1; i++)
		d2 += DaysInMonth[i];
	d2 += countLeapYears(dt2);
	return (d2 - d1 - 1);
}

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head==NULL)
		return -1;
	Date d1 = convertToDate(date1head);
	Date d2 = convertToDate(date2head);
	return getDifference(d1, d2);

}