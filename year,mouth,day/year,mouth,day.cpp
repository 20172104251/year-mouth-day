// year,mouth,day.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Year
{
private:
	int year;
	int month;
	int day;
public:
	Year()
	{
		year = 0;
		month = 0;
		day = 0;
	}
	void setvalue(int a, int b, int c);
	void display();
	Year operator +(Year & ol);
	Year operator -(Year & o2);
	void sum();
};
void Year::setvalue(int a, int b, int c)
{
	year = a;
	month = b;
	day = c;
}
Year Year::operator+(Year & o1)
{
	Year date;
	date.setvalue(year + o1.year, month + o1.month, day + o1.day);
	return date;
}
void Year::display()
{
	cout << year << "年" << month << "月" << day<<"日"<< endl;
}

void Year::sum()
{
	int i,yue;
	int r[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };//闰年
	int p[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//平年
	if (month > 12)
	{
		for (; month > 12;)
		{
			year = year + month / 12;
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				for (; day > r[month + 1];)
				{
					day = day%r[month + 1];
					month++;
				}
			}
			else
			{
				for (; day > p[month + 1];)
				{
					day = day%p[month + 1];
					month++;
				}
			}
		}
	}
	else
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			for (; day > r[month + 1];)
			{
				day = day%r[month + 1];
				month++;
			}
		}
		else
		{
			for (; day > p[month + 1];)
			{
				day = day%p[month + 1];
				month++;
			}
		}
		year=year+month/12;
		month = month % 12;
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			for (; day > r[month + 1];)
			{
				day = day%r[month + 1];
				month++;
			}
		}
		else
		{
			for (; day > p[month + 1];)
			{
				day = day%p[month + 1];
				month++;
			}
		}
		
	}
}
/*
{
	int jyear,yue,i;
	int r[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };//闰年
	int p[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//平年
	yue = month;
	jyear = yue / 12;
	year =year+jyear;
	cout << year << "年" << endl;
	month = yue % 12;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		for (i = 1; i < month; i++)
		{
			yue = r[i];
		}
	}
	else
	{
		for (i = 1; i < month; i++)
		{
			yue = p[i];
		}
//		cout << "月=="<<yue << endl;
	}
	month = month + day / yue;
	day = day%yue;
	year = year + month / 12;	
}*/
int main()
{
	Year q1, q2, q3;
	q1.setvalue(1999, 12, 20);
	q2.setvalue(3, 12, 21);
	q3 = q1 + q2;
	q3.display();
	q3.sum();
	q3.display();
    return 0;
}

