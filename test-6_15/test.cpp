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
	cout << "��ʼ�°�!" << endl;
	int input = 0;
	while (1)
	{
		cin >> input;

		if (input == guessNum)
		{
			cout << "��ϲ�� �¶��ˣ�" << endl;
			break;
		}
		else if (input < guessNum)
		{
			cout << "���С�� ���²°�" << endl;
		}
		else
		{
			cout << "��´��� ���²°�" << endl;
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
		cout << "��ѡ��: ";
		cin >> input;
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			cout << "�˳���Ϸ" << endl;
			break;
		default:
			cout << "������� ����������" << endl;
		}
	} while (input);
	return 0;
}