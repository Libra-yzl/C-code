#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

int Add(int left, int right)
{
	cout << "int Add(int left, int right)" << endl;

	return left + right;
}

double Add(double left, double right)
{
	cout << "double Add(double left, double right)" << endl;

	return left + right;
}

int main()
{
	Add(1, 2);
	Add(1.1, 2.2);

	return 0;
}