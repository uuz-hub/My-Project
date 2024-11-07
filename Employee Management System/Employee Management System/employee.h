#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

// 员工类，继承自工人类
class Employee : public Worker
{
public:
	// 构造函数，用于初始化员工的ID、姓名和部门ID
	Employee(int id, string name, int dpid);

	// 显示员工信息
	virtual void showinfo();
	// 获取员工部门名称
	virtual string getDepartName();
};
