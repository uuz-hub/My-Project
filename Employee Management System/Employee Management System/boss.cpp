#include<iostream>
#include"boss.h"
using namespace std;

// Boss类构造函数，初始化员工的ID、姓名和部门ID
Boss::Boss(int id, string name, int dpid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_departID = dpid;
}

// 获取部门名称的方法，返回“CEO”
string Boss::getDepartName()
{
	return string("CEO");
}

// 显示员工信息的方法，包括职工编号、姓名、岗位和岗位职责
void Boss::showinfo()
{
	cout << "职工编号:" << this->m_ID << "\t职工姓名:" << this->m_Name << "\t职工岗位:" << this->getDepartName() << "\t岗位职责:" << "管理公司所有事物" << endl;
}
