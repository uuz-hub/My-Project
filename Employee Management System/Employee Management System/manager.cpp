#include<iostream>
#include"manager.h"
using namespace std;

// ����Ա���ʵ��
Manager::Manager(int id, string name, int dpid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_departID = dpid;
}

// ��ȡ�������Ƶķ���
string Manager::getDepartName()
{
	return string("����");
}

// ��ʾԱ����Ϣ�ķ���
void Manager::showinfo()
{
	cout << "ְ�����:" << this->m_ID << "\tְ������:" << this->m_Name << "\tְ����λ:" << this->getDepartName() << "\t��λְ��:" << "����ϰ彻��������,���·������Ա��" << endl;
}
