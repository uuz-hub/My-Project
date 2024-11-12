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
	//默认构造
	Students();
	//有参构造
	Students(string id, string name, string pwd);
	//学生菜单
	virtual void openMenu();
	//申请预约
	void applyOrder();
	//查看我的预约
	void showMyOrder();
	//查看所有预约
	void showAllOrder();
	//取消预约
	void cancelOrder();
	//初始化机房
	void initComputerRoom();
	//学生学号
	string m_ID;
	vector<ComputerRoom>vComputerRooms; //机房容器
};