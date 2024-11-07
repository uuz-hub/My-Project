#include<iostream>
#include"workerManager.h" // 包含工人管理类的头文件
#include"worker.h"       // 包含工人类的头文件
#include"employee.h"     // 包含员工类的头文件
#include"manager.h"      // 包含经理类的头文件
#include"boss.h"         // 包含老板类的头文件
using namespace std;

int main() // 主函数，程序入口
{
	WorkerManager wm; // 实例化工人管理类对象
	int choice; // 用户选择的功能选项
	while (1) // 永久循环，直到用户选择退出
	{
		wm.showMenu(); // 显示菜单
		cout << "请选择您要使用的功能!" << endl; // 提示用户选择功能
		cin >> choice; // 接收用户输入
		switch (choice) // 根据用户选择的功能执行相应操作
		{
		case 1:
			wm.addEmp(); // 添加员工
			break;
		case 2:
			wm.Show_Emp(); // 显示员工信息
			break;
		case 3:
			wm.Del_Emp(); // 删除员工
			break;
		case 4:
			wm.Mod_Emp(); // 修改员工信息
			break;
		case 5:
			wm.Search_Emp(); // 查询员工
			break;
		case 6:
			wm.Sort_Emp(); // 排序员工
			break;
		case 7:
			wm.Clean_File(); // 清空文件
			break;
		case 0:
			wm.ExitSystem(); // 退出系统
		default:
			cout << "请输入正确的选项!" << endl; // 提示用户输入正确选项
			system("pause"); // 暂停系统
			system("cls"); // 清屏
			continue; // 继续循环
		}
		system("pause"); // 暂停系统
		system("cls"); // 清屏
	}

	return 0; // 返回0，程序结束
}
