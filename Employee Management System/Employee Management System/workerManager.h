#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "EmpList.txt"
using namespace std;

// 员工管理类，用于处理员工相关操作
class WorkerManager
{
public:
	int m_EmpNum; // 员工数量
	Worker** m_EmpArr; // 员工数组
	bool FileIsEmpty; // 文件是否为空

	WorkerManager(); // 构造函数
	void showMenu(); // 显示菜单
	void addEmp(); // 添加员工
	void save(); // 保存员工信息
	int get_EmpNum(); // 获取员工数量
	void init_Emp(); // 初始化员工信息
	void Show_Emp(); // 显示员工信息
	int IsExist(int id); // 检查员工是否存在
	void Del_Emp(); // 删除员工
	void Mod_Emp(); // 修改员工信息
	void Search_Emp(); // 查找员工
	void Sort_Emp(); // 排序员工
	void Clean_File(); // 清空文件
	void ExitSystem(); // 退出系统
	~WorkerManager(); // 析构函数
};
