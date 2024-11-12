#pragma once
#include<iostream>
using namespace std;

class Identity
{
public:

	virtual void openMenu() = 0; //打开各个身份的子菜单

	string m_Name; //用户名
	string m_Password; //密码
};