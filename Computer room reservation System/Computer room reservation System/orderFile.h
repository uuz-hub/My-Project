#pragma once
#include <iostream>
#include<map>
#include<fstream>
#include"globalFail.h"
using namespace std;

class OrderFile
{
public:
	OrderFile();  //���캯��

	void updateOrder();

	map<int ,map<string,string>>m_orderData; //ԤԼ����
	int m_num; //��¼ԤԼ����
};