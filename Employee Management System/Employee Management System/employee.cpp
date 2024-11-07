#include<iostream>
#include"employee.h"
using namespace std;

// 员工类实现
Employee::Employee(int id, string name, int dpid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_departID = dpid;
}

// 获取员工部门名称
string Employee::getDepartName()
{
	return string("员工");
}

// 显示员工信息
void Employee::showinfo()
{
	cout << "职工编号:" << this->m_ID << "\t职工姓名:" << this->m_Name << "\t职工岗位:" << this->getDepartName() << "\t岗位职责:" << "完成经理交给的任务" << endl;
}
