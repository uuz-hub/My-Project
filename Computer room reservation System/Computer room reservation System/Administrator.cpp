#include "Administrator.h"

Administrator::Administrator()//默认构造
{

}

int countAvailableComputer(const vector<ComputerRoom> & rooms)//计算可用机器数量
{
	int machineCount = 0;  //可用机器数量
	for (vector<ComputerRoom>::const_iterator it = rooms.begin(); it != rooms.end(); it++)
	{
		machineCount += it->m_AvailableMachines;
	}
	return machineCount;
}

bool Administrator::checkRepeat(string id, int type)
{
	if (type == 1)  //检查学生ID是否重复
	{
		for (vector<Students>::iterator it = vStudents.begin(); it != vStudents.end(); it++)  
		{
			if (id == it->m_ID)
			{
				return true;
			}
		}
	}
	else if (type == 2)  //检查教师ID是否重复
	{
		for (vector<Teacher>::iterator it = vTeachers.begin(); it != vTeachers.end(); it++)
		{
			if (id == it->m_T_ID)
			{
				return true;
			}
		}
		
	}
	return false;
}

void Administrator::initComputerRoom() //初始化机房信息
{
	vComputerRooms.clear();
	ifstream ifs;
	ComputerRoom tempComputerRoom = ComputerRoom();
	ifs.open(COMPUTER_FILE, ios::in);
	while (ifs >> tempComputerRoom.m_roomID && ifs >> tempComputerRoom.m_MaxCapacity && ifs >> tempComputerRoom.m_AvailableMachines) //读取机房信息并加入到vector中
	{
		vComputerRooms.push_back(tempComputerRoom);  // 加入到vector中
	}
	ifs.close();
	cout << "当前可用机房数量为: " << vComputerRooms.size() << "  当前可用机器数量为: "  << countAvailableComputer(vComputerRooms) << endl;
}

void Administrator::initVector()   //初始化学生和教师信息
{
	vStudents.clear();
	vTeachers.clear();
	ifstream ifs;
	Students tempStudent;
	ifs.open(STUDENT_FILE, ios::in);
	while (ifs >> tempStudent.m_ID && ifs >> tempStudent.m_Name && ifs >> tempStudent.m_Password) //读取学生信息并加入到vector中
	{
		vStudents.push_back(tempStudent);
	}
	cout << "当前系统中学生数量为: " << vStudents.size() << endl;
	ifs.close();
	Teacher tempTeacher;
	ifs.open(TEACHER_FILE, ios::in);
	while (ifs >> tempTeacher.m_T_ID && ifs >> tempTeacher.m_Name && ifs >> tempTeacher.m_Password)  //读取教师信息并加入到vector中
	{
		vTeachers.push_back(tempTeacher);
	}
	cout << "当前系统中教师数量为: " << vTeachers.size() << endl;
	ifs.close();
}

Administrator::Administrator(string name, string password)//有参构造(姓名,密码)
{
	this->m_Name = name;
	this->m_Password = password;
}

void Administrator::openMenu()//管理员菜单
{
	cout << "欢迎管理员: " << this->m_Name << " 登陆!" << endl;
	cout << "                _______________________________________" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              1.添加账号               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              2.查看账号               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              3.查看机房信息           \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              4.清空预约记录           \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              0.注销登陆               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "                ```````````````````````````````````````" << endl;
	this->initVector();
	this->initComputerRoom();
}

void Administrator::addAccount()//添加账号
{
	string FileName;
	int select;
	ofstream ofs;
	string errorMsg;
	cout << "请选择添加账号的身份:" << endl;
	cout << "1.学生" << endl;
	cout << "2.教师" << endl;
	while (1)
	{
		cin >> select;
		if (select == 1) //添加学生
		{
			FileName = STUDENT_FILE;
			cout << "请输入学号:" << endl;
			errorMsg = "学号已存在!";
			break;
		}
		else if (select == 2) //添加教师
		{
			FileName = TEACHER_FILE;
			cout << "请输入工号:" << endl;
			errorMsg = "工号已存在!";
			break;
		}
		else
		{
			cout << "请选择正确的选项!" << endl;
			continue;
		}
	}
	ofs.open(FileName, ios::out | ios::app);
	string id;
	string name;
	string password;
	while (1) //检查输入的ID是否重复
	{
		cin >> id;
		if (checkRepeat(id, select))
		{
			cout << errorMsg << endl;
			return;
		}
		break;
	}
	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> password;
	ofs << id << " " << name << " " << password << endl;
	ofs.close();
	cout << "添加账户成功!" << endl;
}

void Administrator::showAccount()//查看账号
{
	cout << "请选择想要查看账号的类型:" << endl;
	cout << "1.查看所有的学生" << endl;
	cout << "2.查看所有的教师" << endl;
	int select;
	while (1)
	{
		cin >> select;
		switch (select)
		{
		case 1:
			for_each
			(
				vStudents.begin(), vStudents.end(), [](Students s) //使用lambda表达式遍历所有学生信息并输出
				{
					cout << left <<  "学号: " << setw(10) << s.m_ID  << "用户名: " << setw(15) << s.m_Name << "密码: " <<  setw(15) <<s.m_Password << endl;
				}
			);
			return;
		case 2:
			for_each
			(
				vTeachers.begin(), vTeachers.end(), [](Teacher t) //使用lambda表达式遍历所有教师信息并输出
				{
					cout << left << "工号: " << setw(10) << t.m_T_ID << "用户名: " << setw(15) << t.m_Name << "密码: " << setw(15) << t.m_Password << endl;
				}
			);
			return;
		default:
			cout << "请选择正确的选项!" << endl;
			continue;
		}
	}
}

void Administrator::showComputerRoom()//查看机房信息
{
	cout << "当前所有机房信息如下:" << endl;
	for_each
	(
		vComputerRooms.begin(), vComputerRooms.end(), [](ComputerRoom cpr)
		{
			cout << left << "机房编号: " << cpr.m_roomID << "  最大容量: " << setw(5) << cpr.m_MaxCapacity << "当前可用设备数: " << cpr.m_AvailableMachines << endl;
		}
	);
}

void Administrator::clearRecord()//清空预约记录
{
	cout << "确定要清空所有预约记录吗?" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
	int select;
	while (1)
	{
		cin >> select;
		if (select == 1)
		{
			ofstream ofs;
			ofs.open(ORDER_FILE, ios::trunc);
			ofs.close();
			cout << "预约记录已清空!" << endl;
			return;
		}
		else if (select == 2)
		{
			cout << "操作已取消!" << endl;
			cout << "正在返回操作界面..." << endl;
			return;
		}
		else
		{
			cout << "请选择正确的选项!" << endl;
			continue;
		}
	}
}

