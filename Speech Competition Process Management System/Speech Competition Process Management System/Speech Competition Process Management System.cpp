#include<iostream>
#include"MainManager.h"
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	MainManager m;
	int choice;  //�û�ѡ���ѡ��
	while (1)  //ѭ��
	{

		m.showMenu();
		cout << "��ѡ����Ҫʹ�õĹ���!" << endl;
		cin >> choice;
		switch (choice)
		{
			 case 1:  //��ʼ�ݽ�����
				 m.startSpeech();
				 break;
			 case 2:  //�鿴�����¼
				 m.showHistory();
				 break;
			 case 3:  //��ձ�����¼
				 m.clearRecord();
				 break;
			 case 0:  //�˳�ϵͳ
				 m.exitSystem();
				 break;
			 default:
				 cout << "��ѡ����ȷ��ѡ��!" << endl;
				 system("pause");
				 system("cls");
				 continue;
		}
		system("pause");  //��ͣ���򣬵ȴ��û�����
		system("cls");  //����
	}

	return 0;
}