#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

// ����Ա�࣬�̳��Թ�����
class Manager : public Worker
{
public:
	// ���캯������ʼ������Ա��ID�����ֺͲ���ID
	Manager(int id,string name , int dpid);

	// ��ʾ����Ա��Ϣ���麯��
	virtual void showinfo();
	
	// ��ȡ�������Ƶ��麯��
	virtual string getDepartName();
};
