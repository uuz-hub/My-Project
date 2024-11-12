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
	//默认构造
	Administrator();
	//有参构造(姓名,密码)
	Administrator(string name, string password);
	//管理员菜单
	virtual void openMenu();
	//添加账号
	void addAccount();
	//查看账号
	void showAccount();
	//查看机房信息
	void showComputerRoom();
	//清空预约记录
	void clearRecord();
	//初始化容器;
	void initVector();
	//初始化机房信息
	void initComputerRoom();
	
	bool checkRepeat(string id,int type); //检查是否重复

	vector<Students>vStudents; //学生容器
	vector<Teacher>vTeachers; //教师容器
	vector<ComputerRoom>vComputerRooms; //机房容器
};