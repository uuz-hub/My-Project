#include<iostream>
#include"boss.h"
using namespace std;

// Boss�๹�캯������ʼ��Ա����ID�������Ͳ���ID
Boss::Boss(int id, string name, int dpid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_departID = dpid;
}

// ��ȡ�������Ƶķ��������ء�CEO��
string Boss::getDepartName()
{
	return string("CEO");
}

// ��ʾԱ����Ϣ�ķ���������ְ����š���������λ�͸�λְ��
void Boss::showinfo()
{
	cout << "ְ�����:" << this->m_ID << "\tְ������:" << this->m_Name << "\tְ����λ:" << this->getDepartName() << "\t��λְ��:" << "����˾��������" << endl;
}
