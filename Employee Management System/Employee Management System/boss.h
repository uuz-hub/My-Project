#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

// Boss类，继承自Worker类
class Boss : public Worker
{
public:
	// 构造函数，初始化Boss对象的id、name和dpid
	Boss(int id, string name, int dpid);

	// 重写showinfo方法，显示Boss信息
	virtual void showinfo();
	
	// 重写getDepartName方法，获取Boss所在部门名称
	virtual string getDepartName();
};
