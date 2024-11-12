#include<iostream>
#include<string>
#include<fstream>
#include"Identity.h"
#include"globalFail.h"
#include "MainSystem.h"
#include"Students.h"
#include"Teacher.h"
#include"Administrator.h"
using namespace std;

void AdminModel(Identity*& person)
{
	while (1) //�������Աϵͳ��
	{
		system("pause");
		system("cls");
		Administrator* admin = (Administrator*)person;  //������ָ��ת��Ϊ����ָ��,������������Ա����
		cout << "========================��ӭʹ��ԤԼϵͳ����Ա��============================" << endl;
		person->openMenu(); // �Ӹ�������Ӳ˵�
		int choice;
		cout << "��ѡ����Ҫʹ�õĹ���:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			admin->addAccount(); // ����˻�
			break;
		case 2:
			admin->showAccount(); // ��ʾ�˻�
			break;
		case 3:
			admin->showComputerRoom(); // ��ʾ���������
			break;
		case 4:
			admin->clearRecord(); // ��ռ�¼
			break;
		case 0: //ע����½
			delete person; // ɾ������Ա����
			cout << "ע���ɹ�!" << endl;
			return;
		default:
			cout << "��ѡ����ȷ��ѡ��!" << endl;
			continue; // ������һ��ѭ��
		}
	}
}

void StudentModel(Identity*& person)
{
	while (1)
	{
		system("pause");
		system("cls");
		cout << "========================��ӭʹ��ԤԼϵͳѧ����=============================" << endl;
		person->openMenu(); // ��ʾ�˵�
		Students* stu = (Students*)person;
		int choice;
		cout << "��ѡ����Ҫʹ�õĹ���:" << endl;
		cin >> choice;
		switch (choice)
		{
			 case 1:  //����ԤԼ
				 stu->applyOrder();
				 break;
			 case 2:  //�鿴�ҵ�ԤԼ
				 stu->showMyOrder();
				 break;
			 case 3:  //�鿴����ԤԼ
				 stu->showAllOrder();
				 break;
			 case 4:  //ȡ��ԤԼ
				 stu->cancelOrder();
				 break;
			 case 0:  // ע����½
				 delete person; // ɾ��ѧ������
				 cout << "ע���ɹ�!" << endl;
				 return;
		default:
			cout << "��ѡ����ȷ��ѡ��!" << endl;
			continue; // ������һ��ѭ��
		}
	}
}

void TeacherModel(Identity*& person)
{
	while (1)
	{
		system("pause");
		system("cls");
		cout << "========================��ӭʹ��ԤԼϵͳ��ʦ��=============================" << endl;
		person->openMenu(); // ��ʾ�˵�
		Teacher* tea = (Teacher*)person;
		int choice;
		cout << "��ѡ����Ҫʹ�õĹ���:" << endl;
		cin >> choice;
		switch (choice)
		{
			 case 1:  //�鿴����ԤԼ
				 tea->showAllOrder();
				 break;
			 case 2:  //���ԤԼ
				 tea->examOrder();
				 break;
			 case 0:  // ע����½
				 delete person; // ɾ����ʦ����
				 cout << "ע���ɹ�!" << endl;
				 return;
		default:
			cout << "��ѡ����ȷ��ѡ��!" << endl;
			continue; // ������һ��ѭ��
		}
	}
}

void LoginSystem(string filename, int type)//��½ϵͳ (����1,�ļ��� , ������,�������)
{
	Identity* person = NULL; //��������ָ��
	ifstream ifs;
	string id;
	string name;
	string password;
	string Fid, Fname, Fpassword;
	//��ʼ��֤�û���������
	int count = 0;
	while (1)
	{
		ifs.open(filename, ios::in);
		if (!ifs.is_open())
		{
			cout << "�ļ�������!" << endl;
			return;
		}
		if (type == 1)//ѡ��ѧ����
		{
			cout << "������ѧ��:" << endl;
			cin >> id;
		}
		else if (type == 2)//ѡ���ʦ��
		{
			cout << "�����빤��:" << endl;
			cin >> id;
		}
		// ����Աֱ�������û���������
		cout << "�������û���:" << endl;
		cin >> name;
		cout << "�������˻�����:" << endl;
		cin >> password;
		if (type == 1) // ѧ������֤
		{
			while (ifs >> Fid && ifs >> Fname && ifs >> Fpassword)
			{
				if (Fid == id &&Fname == name && Fpassword == password)
				{
					cout << "ѧ������֤��½�ɹ�!" << endl;
					person = new Students(id, name, password);
					StudentModel(person);
					return;
				}
			}
		}
		else if (type == 2) // ��ʦ����֤
		{
			while (ifs >> Fid && ifs >> Fname && ifs >> Fpassword)
			{
				if (Fid == id && Fname == name && Fpassword == password)
				{
					cout << "��ʦ����֤��½�ɹ�!" << endl;
					person = new Teacher(id, name, password);
					TeacherModel(person);
					return;
				}
			}
		}
		else if (type == 3) // ����Ա����֤
		{
			while (ifs >> Fname && ifs >> Fpassword)
			{
				if (Fname == name && Fpassword == password)
				{
					cout << "�������֤��½�ɹ�!" << endl;
					person = new Administrator(name, password);
					AdminModel(person);
					return;
				}
			}
		}
		count++;
		if (count <= 3)
		{
			cout << "�û������������! �㻹�� " << 3 - count << " �λ���,����������! " << endl;
		}
		else
		{
			cout << "��½ʧ��!��������������,���Ժ�����!" << endl;
			return; //�˳���¼ϵͳ
		}
		ifs.close();
	}
}
// ���������������
int main()
{
	MainSystem ms; // ����һ����ϵͳ��ʵ��
	int choice; // �û�ѡ��Ĳ˵���
	while (1) // ����ѭ����ֱ���û�ѡ���˳�
	{
		cout << "========================��ӭʹ�ü��������ԤԼϵͳ==========================" << endl;
		ms.selectMenu(); // ��ʾ�˵�
		cout << "�������������:" << endl;
		cin >> choice; // �����û����ѡ��
		switch (choice) // �����û�ѡ��
		{
			case 1: // ѧ����
				LoginSystem(STUDENT_FILE, 1);
				break;
			case 2: // ��ʦ��
				LoginSystem(TEACHER_FILE, 2);
				break;
			case 3: // ����Ա��
				LoginSystem(ADMIN_FILE, 3);
				break;
			case 0: // �˳�ϵͳ
				ms.exitSystem();
				break;
			default: // ������Ч����
				cout << "��������ȷ��ѡ��!" << endl;
				system("pause");
				system("cls");
				continue; // ������һ��ѭ��
		}
		system("pause");
		system("cls"); // ����
	}

	return 0; // �������
}
