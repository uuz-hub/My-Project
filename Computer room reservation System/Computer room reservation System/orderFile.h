#pragma once
#include <iostream>
#include<map>
#include<fstream>
#include"globalFail.h"
using namespace std;

class OrderFile
{
public:
	OrderFile();  //构造函数

	void updateOrder();

	map<int ,map<string,string>>m_orderData; //预约数据
	int m_num; //记录预约数量
};