#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

// 管理员类，继承自工人类
class Manager : public Worker
{
public:
	// 构造函数，初始化管理员的ID、名字和部门ID
	Manager(int id,string name , int dpid);

	// 显示管理员信息的虚函数
	virtual void showinfo();
	
	// 获取部门名称的虚函数
	virtual string getDepartName();
};
