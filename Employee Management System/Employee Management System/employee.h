#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

// Ա���࣬�̳��Թ�����
class Employee : public Worker
{
public:
	// ���캯�������ڳ�ʼ��Ա����ID�������Ͳ���ID
	Employee(int id, string name, int dpid);

	// ��ʾԱ����Ϣ
	virtual void showinfo();
	// ��ȡԱ����������
	virtual string getDepartName();
};
