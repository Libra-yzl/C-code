#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int& ra = a;
	int&& rra = a + b;
	cout << &a << endl;
	//cout << &(a + b) << endl; // ���ʽ����Ϊ��ֵ
	return 0;
}