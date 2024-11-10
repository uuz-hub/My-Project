#include<iostream>
#include"MainManager.h"
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	MainManager m;
	int choice;  //用户选择的选项
	while (1)  //循环
	{

		m.showMenu();
		cout << "请选择您要使用的功能!" << endl;
		cin >> choice;
		switch (choice)
		{
			 case 1:  //开始演讲比赛
				 m.startSpeech();
				 break;
			 case 2:  //查看往届记录
				 m.showHistory();
				 break;
			 case 3:  //清空比赛记录
				 m.clearRecord();
				 break;
			 case 0:  //退出系统
				 m.exitSystem();
				 break;
			 default:
				 cout << "请选择正确的选项!" << endl;
				 system("pause");
				 system("cls");
				 continue;
		}
		system("pause");  //暂停程序，等待用户输入
		system("cls");  //清屏
	}

	return 0;
}