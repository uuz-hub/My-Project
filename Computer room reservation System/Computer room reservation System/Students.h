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

class Students :public Identity
{
public:
	//Ĭ�Ϲ���
	Students();
	//�вι���
	Students(string id, string name, string pwd);
	//ѧ���˵�
	virtual void openMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴�ҵ�ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
	//��ʼ������
	void initComputerRoom();
	//ѧ��ѧ��
	string m_ID;
	vector<ComputerRoom>vComputerRooms; //��������
};