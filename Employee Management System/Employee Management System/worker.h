#pragma once
#include<iostream>
#include<string>
using namespace std;

// ������Ա��
class Worker
{
public:
	int m_ID;          // ������ԱID
	int m_departID;    // ��������ID
	string m_Name;     // ������Ա����

	// ��ʾ������Ա��Ϣ�Ĵ��麯��
	virtual void showinfo() = 0;
	// ��ȡ�����������ƵĴ��麯��
	virtual string getDepartName() = 0;
};
