

//#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int year, month, day;
}Date;

int isLeapYear(int year) {
	//checks if a given year has 29 or 28 days in February
	//Input: year - positiv integer
	//Output: 1 if given year is a leap one
	//		  0 otherwise
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int validateDate(Date data)
{
	//validateDate validates a given date
	//Input: data - date type -- struct which has year, month and day as integers
	//Output: 1 - if the given date is valid
	//		  0 - otherwise
	if (data.day < 1 || data.day > 31 || data.month < 1 || data.month > 12 || data.year < 1)
		return 0;
	if (((data.month % 2 == 1 && data.month <= 7) || (data.month % 2 == 0 && data.month >= 8)) && data.day > 31)
		return 0;
	if (((data.month % 2 == 0 && data.month <= 7) || (data.month % 2 == 1 && data.month >= 8)) && data.day > 30)
		return 0;
	if (data.month == 2 && isLeapYear(data.year) && data.day > 29)
		return 0;
	if (data.month == 2 && !isLeapYear(data.year) && data.day > 28)
		return 0;
	return 1;
}

int getDayNbFromDate(Date data)
{
	//getDayNbFromDate returns the day of the year from the given date
	//Input: data - struct which has year, month and day as integers
	//Output: dayNumber - number
	//		  0 - in case of invalid date
	if(validateDate(data) == 0)
		return 0;
	int months[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = data.day;
	for (int i = 1; i < data.month; i++)
		sum += months[i];
	return sum + (isLeapYear(data.year) && data.month > 2);
}

void putZeroInArrayOfChars(char *array, int lenArray) {
	for (int i = 0; i < lenArray; i++)
		array[i] = 0;
}

int main()
{
	char dates[500];
	int i=0, counterDateFilds=0, number=0;
	putZeroInArrayOfChars(dates, 500);
	Date dateInternal;
	scanf("%[^'\n']s", &dates);
	while (dates[i] != 0)
	{
		if (dates[i] == '-')
			counterDateFilds++;
		if (dates[i] == ' ') {
			counterDateFilds = 0;
			dateInternal.year = number;
			number = 0;
			printf("%d ", getDayNbFromDate(dateInternal));
		}
		else if (counterDateFilds == 1)
			dateInternal.day = number,
			counterDateFilds++,
			number = 0;
		else if (counterDateFilds == 3)
			dateInternal.month = number,
			counterDateFilds++,
			number = 0;
		if(dates[i]>='0' && dates[i]<='9')
			number = number * 10 + (dates[i] - '0');
		i++;
	}
	dateInternal.year = number;
	printf("%d ", getDayNbFromDate(dateInternal));
	return 0;
}


