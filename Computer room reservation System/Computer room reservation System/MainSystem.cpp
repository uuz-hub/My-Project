#include "MainSystem.h"

// MainSystem类的构造函数
MainSystem::MainSystem() 
{

}

// 选择菜单的成员函数，显示系统菜单选项
void MainSystem::selectMenu()
{
	cout << "                _______________________________________" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              1.学生代表               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              2.教    师               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              3.管 理 员               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              0.退出系统               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "                ```````````````````````````````````````" << endl;
}

// 退出系统的成员函数，处理退出流程
void MainSystem::exitSystem()
{
	cout << "正在退出系统..." << endl;
	system("pause");
	cout << "退出成功！" << endl;
	exit(0);
}

// MainSystem类的析构函数
MainSystem::~MainSystem()
{

}
