#pragma once
#include<iostream>
#include<string>
using namespace std;

// 工作人员类
class Worker
{
public:
	int m_ID;          // 工作人员ID
	int m_departID;    // 所属部门ID
	string m_Name;     // 工作人员姓名

	// 显示工作人员信息的纯虚函数
	virtual void showinfo() = 0;
	// 获取所属部门名称的纯虚函数
	virtual string getDepartName() = 0;
};
