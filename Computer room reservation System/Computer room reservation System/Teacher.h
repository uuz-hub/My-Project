#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<iomanip>
#include"ComputerRoom.h"
#include"globalFail.h"
#include"Identity.h"
#include"orderFile.h"
using namespace std;

class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���(����,����,����)
	Teacher(string id, string name, string pwd);
	//��ʦ�˲˵�
	virtual void openMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void examOrder();
	//����
	string m_T_ID;
};