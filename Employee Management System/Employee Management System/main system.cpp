#include<iostream>
#include"workerManager.h" // �������˹������ͷ�ļ�
#include"worker.h"       // �����������ͷ�ļ�
#include"employee.h"     // ����Ա�����ͷ�ļ�
#include"manager.h"      // �����������ͷ�ļ�
#include"boss.h"         // �����ϰ����ͷ�ļ�
using namespace std;

int main() // ���������������
{
	WorkerManager wm; // ʵ�������˹��������
	int choice; // �û�ѡ��Ĺ���ѡ��
	while (1) // ����ѭ����ֱ���û�ѡ���˳�
	{
		wm.showMenu(); // ��ʾ�˵�
		cout << "��ѡ����Ҫʹ�õĹ���!" << endl; // ��ʾ�û�ѡ����
		cin >> choice; // �����û�����
		switch (choice) // �����û�ѡ��Ĺ���ִ����Ӧ����
		{
		case 1:
			wm.addEmp(); // ���Ա��
			break;
		case 2:
			wm.Show_Emp(); // ��ʾԱ����Ϣ
			break;
		case 3:
			wm.Del_Emp(); // ɾ��Ա��
			break;
		case 4:
			wm.Mod_Emp(); // �޸�Ա����Ϣ
			break;
		case 5:
			wm.Search_Emp(); // ��ѯԱ��
			break;
		case 6:
			wm.Sort_Emp(); // ����Ա��
			break;
		case 7:
			wm.Clean_File(); // ����ļ�
			break;
		case 0:
			wm.ExitSystem(); // �˳�ϵͳ
		default:
			cout << "��������ȷ��ѡ��!" << endl; // ��ʾ�û�������ȷѡ��
			system("pause"); // ��ͣϵͳ
			system("cls"); // ����
			continue; // ����ѭ��
		}
		system("pause"); // ��ͣϵͳ
		system("cls"); // ����
	}

	return 0; // ����0���������
}
