/*************************************************************************
	> File Name: test.cpp
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 四  7/25 13:51:30 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
class Date
{
public:
	Date()
	{}

	Date(int year, int month, int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2(2018, 11, 30);
	
	system("pause");
	return 0;
}

