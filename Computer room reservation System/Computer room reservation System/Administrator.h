#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include"Identity.h"
#include"Students.h"
#include"Teacher.h"
#include"globalFail.h"
#include"ComputerRoom.h"

using namespace std;

class Administrator :public Identity
{
public:
	//Ĭ�Ϲ���
	Administrator();
	//�вι���(����,����)
	Administrator(string name, string password);
	//����Ա�˵�
	virtual void openMenu();
	//����˺�
	void addAccount();
	//�鿴�˺�
	void showAccount();
	//�鿴������Ϣ
	void showComputerRoom();
	//���ԤԼ��¼
	void clearRecord();
	//��ʼ������;
	void initVector();
	//��ʼ��������Ϣ
	void initComputerRoom();
	
	bool checkRepeat(string id,int type); //����Ƿ��ظ�

	vector<Students>vStudents; //ѧ������
	vector<Teacher>vTeachers; //��ʦ����
	vector<ComputerRoom>vComputerRooms; //��������
};