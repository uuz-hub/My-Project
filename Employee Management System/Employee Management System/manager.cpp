#include<iostream>
#include"manager.h"
using namespace std;

// 管理员类的实现
Manager::Manager(int id, string name, int dpid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_departID = dpid;
}

// 获取部门名称的方法
string Manager::getDepartName()
{
	return string("经理");
}

// 显示员工信息的方法
void Manager::showinfo()
{
	cout << "职工编号:" << this->m_ID << "\t职工姓名:" << this->m_Name << "\t职工岗位:" << this->getDepartName() << "\t岗位职责:" << "完成老板交给的任务,并下发任务给员工" << endl;
}
