#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

// Boss�࣬�̳���Worker��
class Boss : public Worker
{
public:
	// ���캯������ʼ��Boss�����id��name��dpid
	Boss(int id, string name, int dpid);

	// ��дshowinfo��������ʾBoss��Ϣ
	virtual void showinfo();
	
	// ��дgetDepartName��������ȡBoss���ڲ�������
	virtual string getDepartName();
};
