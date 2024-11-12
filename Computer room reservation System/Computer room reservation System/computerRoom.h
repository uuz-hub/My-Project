#pragma once
#include<iostream>
using namespace std;

class ComputerRoom
{
public:
	
	int m_roomID; //机房编号

	int m_MaxCapacity; //机房最大容量

	int m_AvailableMachines; //机房当前容量
};