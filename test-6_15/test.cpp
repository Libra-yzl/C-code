#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <time.h>

using namespace std;

void menu()
{
	cout << "*********************************************************" << endl;
	cout << "                 1.play             0.exit               " << endl;
	cout << "*********************************************************" << endl;
}

void game()
{
	int guessNum = rand() % 100 + 1;
	cout << "开始猜吧!" << endl;
	int input = 0;
	while (1)
	{
		cin >> input;

		if (input == guessNum)
		{
			cout << "恭喜你 猜对了！" << endl;
			break;
		}
		else if (input < guessNum)
		{
			cout << "你猜小了 重新猜吧" << endl;
		}
		else
		{
			cout << "你猜大了 重新猜吧" << endl;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		cout << "请选择: ";
		cin >> input;
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			cout << "退出游戏" << endl;
			break;
		default:
			cout << "输入错误 请重新输入" << endl;
		}
	} while (input);
	return 0;
}