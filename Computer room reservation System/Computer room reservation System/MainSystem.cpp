#include "MainSystem.h"

// MainSystem��Ĺ��캯��
MainSystem::MainSystem() 
{

}

// ѡ��˵��ĳ�Ա��������ʾϵͳ�˵�ѡ��
void MainSystem::selectMenu()
{
	cout << "                _______________________________________" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              1.ѧ������               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              2.��    ʦ               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              3.�� �� Ա               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              0.�˳�ϵͳ               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "                ```````````````````````````````````````" << endl;
}

// �˳�ϵͳ�ĳ�Ա�����������˳�����
void MainSystem::exitSystem()
{
	cout << "�����˳�ϵͳ..." << endl;
	system("pause");
	cout << "�˳��ɹ���" << endl;
	exit(0);
}

// MainSystem�����������
MainSystem::~MainSystem()
{

}
