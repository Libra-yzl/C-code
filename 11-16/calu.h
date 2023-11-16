#pragma once
#include <iostream>

using namespace std;

void calu(int n)
{
	int ret = 0;
	int day = 0;
	int count = 0;
	while (ret < 350)
	{
		ret += n;
		n /= 2;
		if (n == 0) {
			count++;
			n = 2;
		}
		day++;
	}
	cout << day - count << endl;
	cout << day << endl;
}