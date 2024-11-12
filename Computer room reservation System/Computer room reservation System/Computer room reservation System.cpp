#include<iostream>
#include<string>
#include<fstream>
#include"Identity.h"
#include"globalFail.h"
#include "MainSystem.h"
#include"Students.h"
#include"Teacher.h"
#include"Administrator.h"
using namespace std;

void AdminModel(Identity*& person)
{
	while (1) //进入管理员系统端
	{
		system("pause");
		system("cls");
		Administrator* admin = (Administrator*)person;  //将父类指针转化为子类指针,方便调用子类成员函数
		cout << "========================欢迎使用预约系统管理员端============================" << endl;
		person->openMenu(); // 从父类调用子菜单
		int choice;
		cout << "请选择您要使用的功能:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			admin->addAccount(); // 添加账户
			break;
		case 2:
			admin->showAccount(); // 显示账户
			break;
		case 3:
			admin->showComputerRoom(); // 显示计算机房间
			break;
		case 4:
			admin->clearRecord(); // 清空记录
			break;
		case 0: //注销登陆
			delete person; // 删除管理员对象
			cout << "注销成功!" << endl;
			return;
		default:
			cout << "请选择正确的选项!" << endl;
			continue; // 继续下一轮循环
		}
	}
}

void StudentModel(Identity*& person)
{
	while (1)
	{
		system("pause");
		system("cls");
		cout << "========================欢迎使用预约系统学生端=============================" << endl;
		person->openMenu(); // 显示菜单
		Students* stu = (Students*)person;
		int choice;
		cout << "请选择您要使用的功能:" << endl;
		cin >> choice;
		switch (choice)
		{
			 case 1:  //申请预约
				 stu->applyOrder();
				 break;
			 case 2:  //查看我的预约
				 stu->showMyOrder();
				 break;
			 case 3:  //查看所有预约
				 stu->showAllOrder();
				 break;
			 case 4:  //取消预约
				 stu->cancelOrder();
				 break;
			 case 0:  // 注销登陆
				 delete person; // 删除学生对象
				 cout << "注销成功!" << endl;
				 return;
		default:
			cout << "请选择正确的选项!" << endl;
			continue; // 继续下一轮循环
		}
	}
}

void TeacherModel(Identity*& person)
{
	while (1)
	{
		system("pause");
		system("cls");
		cout << "========================欢迎使用预约系统教师端=============================" << endl;
		person->openMenu(); // 显示菜单
		Teacher* tea = (Teacher*)person;
		int choice;
		cout << "请选择您要使用的功能:" << endl;
		cin >> choice;
		switch (choice)
		{
			 case 1:  //查看所有预约
				 tea->showAllOrder();
				 break;
			 case 2:  //审核预约
				 tea->examOrder();
				 break;
			 case 0:  // 注销登陆
				 delete person; // 删除教师对象
				 cout << "注销成功!" << endl;
				 return;
		default:
			cout << "请选择正确的选项!" << endl;
			continue; // 继续下一轮循环
		}
	}
}

void LoginSystem(string filename, int type)//登陆系统 (参数1,文件名 , 参数二,身份类型)
{
	Identity* person = NULL; //创建父类指针
	ifstream ifs;
	string id;
	string name;
	string password;
	string Fid, Fname, Fpassword;
	//开始验证用户名和密码
	int count = 0;
	while (1)
	{
		ifs.open(filename, ios::in);
		if (!ifs.is_open())
		{
			cout << "文件不存在!" << endl;
			return;
		}
		if (type == 1)//选择学生端
		{
			cout << "请输入学号:" << endl;
			cin >> id;
		}
		else if (type == 2)//选择教师端
		{
			cout << "请输入工号:" << endl;
			cin >> id;
		}
		// 管理员直接输入用户名和密码
		cout << "请输入用户名:" << endl;
		cin >> name;
		cout << "请输入账户密码:" << endl;
		cin >> password;
		if (type == 1) // 学生端验证
		{
			while (ifs >> Fid && ifs >> Fname && ifs >> Fpassword)
			{
				if (Fid == id &&Fname == name && Fpassword == password)
				{
					cout << "学生端验证登陆成功!" << endl;
					person = new Students(id, name, password);
					StudentModel(person);
					return;
				}
			}
		}
		else if (type == 2) // 教师端验证
		{
			while (ifs >> Fid && ifs >> Fname && ifs >> Fpassword)
			{
				if (Fid == id && Fname == name && Fpassword == password)
				{
					cout << "教师端验证登陆成功!" << endl;
					person = new Teacher(id, name, password);
					TeacherModel(person);
					return;
				}
			}
		}
		else if (type == 3) // 管理员端验证
		{
			while (ifs >> Fname && ifs >> Fpassword)
			{
				if (Fname == name && Fpassword == password)
				{
					cout << "管理端验证登陆成功!" << endl;
					person = new Administrator(name, password);
					AdminModel(person);
					return;
				}
			}
		}
		count++;
		if (count <= 3)
		{
			cout << "用户名或密码错误! 你还有 " << 3 - count << " 次机会,请重新输入! " << endl;
		}
		else
		{
			cout << "登陆失败!输入错误次数过多,请稍后再试!" << endl;
			return; //退出登录系统
		}
		ifs.close();
	}
}
// 主函数，程序入口
int main()
{
	MainSystem ms; // 创建一个主系统的实例
	int choice; // 用户选择的菜单项
	while (1) // 无限循环，直到用户选择退出
	{
		cout << "========================欢迎使用计算机教室预约系统==========================" << endl;
		ms.selectMenu(); // 显示菜单
		cout << "请输入您的身份:" << endl;
		cin >> choice; // 输入用户身份选择
		switch (choice) // 处理用户选择
		{
			case 1: // 学生端
				LoginSystem(STUDENT_FILE, 1);
				break;
			case 2: // 教师端
				LoginSystem(TEACHER_FILE, 2);
				break;
			case 3: // 管理员端
				LoginSystem(ADMIN_FILE, 3);
				break;
			case 0: // 退出系统
				ms.exitSystem();
				break;
			default: // 处理无效输入
				cout << "请输入正确的选项!" << endl;
				system("pause");
				system("cls");
				continue; // 继续下一轮循环
		}
		system("pause");
		system("cls"); // 清屏
	}

	return 0; // 程序结束
}
