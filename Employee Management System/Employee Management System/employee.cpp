#include<iostream>
#include"employee.h"
using namespace std;

// Ա����ʵ��
Employee::Employee(int id, string name, int dpid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_departID = dpid;
}

// ��ȡԱ����������
string Employee::getDepartName()
{
	return string("Ա��");
}

// ��ʾԱ����Ϣ
void Employee::showinfo()
{
	cout << "ְ�����:" << this->m_ID << "\tְ������:" << this->m_Name << "\tְ����λ:" << this->getDepartName() << "\t��λְ��:" << "��ɾ�����������" << endl;
}
