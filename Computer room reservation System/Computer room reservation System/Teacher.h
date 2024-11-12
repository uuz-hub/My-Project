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
	//默认构造
	Teacher();
	//有参构造(工号,姓名,密码)
	Teacher(string id, string name, string pwd);
	//教师端菜单
	virtual void openMenu();
	//查看所有预约
	void showAllOrder();
	//审核预约
	void examOrder();
	//工号
	string m_T_ID;
};