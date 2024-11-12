#include "Students.h"

Students::Students()//默认构造
{

}

void Students::initComputerRoom()//初始化计算机房间
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
}

Students::Students(string id, string name, string pwd)//有参构造
{
	this->m_Name = name;
	this->m_ID = id;
	this->m_Password = pwd;
}

void Students::openMenu()//学生菜单
{
	cout << "欢迎学生用户 : " << this->m_Name << " 登陆!" << endl;
	cout << "                _______________________________________" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              1.申请预约               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              2.查看我的预约           \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              3.查看所有预约           \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              4.取消预约               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              0.注销登陆               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "                ```````````````````````````````````````" << endl;
	this->initComputerRoom();
}

void Students::applyOrder()//申请预约
{
	cout << "机房可供预约使用的时间为周一~周五" << endl;
	cout << "请选择您要预约的时间: " << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int data = 0;
	int time = 0;
	int room = 0;
	while(1)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		else
		{
			cout << "请选择正确的时间!" << endl;
			continue;
		}
	}
	cout << "请选择申请预约的时间段:" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (1)
	{
		cin >> time;
		switch (time)
		{
		case 1:		
			break;
		case 2:
			break;
		default:
			cout << "请选择正确的时间段!" << endl;
			continue;
		}
		if (time == 1 || time == 2)
		{
			break;
		}
	}
	cout << "请选择需要预约使用的机房:" << endl;
	for_each
	(
		vComputerRooms.begin(), vComputerRooms.end(), [](ComputerRoom room)
		{
			cout << left << "机房编号: " << room.m_roomID << "机房最大容量: " << setw(5) << room.m_MaxCapacity << "机房当前可用设备数量: " << room.m_AvailableMachines << endl;
		}
	);
	while (1)
	{
		cin >> room;
		if (room == 1 || room == 2 || room == 3)
		{
			break;
		}
		else
		{
			cout << "请选择正确的选项!" << endl;
			continue;
		}
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app); // 追加模式打开文件
	ofs << "room:" << room << " " << "time:" << time << " " << "date:" << data << " " << "S_id:" << this->m_ID << " " << "S_name:" << this->m_Name << " " << "status:" << 1 << endl;
	ofs.close();
	cout << "预约成功!当前正在审核中..." << endl;
}

void Students::showMyOrder()//查看我的预约
{
	OrderFile of;
	if (of.m_num == 0) // 没有预约记录
	{
		cout << "暂无预约记录!" << endl;
		return;
	}
	cout << "您有以下预约记录:" << endl;
	for (int i = 0; i < of.m_num; i++)
	{
		if (this->m_ID == of.m_orderData[i]["S_id"]) // 找到该学生的预约记录
		{
			cout << "预约机房号: " << of.m_orderData[i]["room"];
			cout << "  预约时间段: " << (of.m_orderData[i]["time"] == "1" ? "上午" : "下午");
			cout << "  预约日期: 周" << of.m_orderData[i]["date"];
			string status = "  状态: ";
			// 状态: 0-取消预约 1-审核中 2-已预约 -1 预约失败
			{
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "已预约";
				}
				else if (of.m_orderData[i]["status"] == "-1")
				{
					status += "预约失败";
				}
				else
				{
					status += "取消预约";
				}
			}
			cout << status << endl;
		}
	}
}

void Students::showAllOrder()//查看所有预约
{
	OrderFile of;
	if (of.m_num == 0)
	{
		cout << "暂无预约记录!" << endl;
		return;
	}
	cout << "所有预约记录如下: " << endl;
	for (int i = 0; i < of.m_num; i++)
	{
		cout << i + 1 << " " << "机房号: " << of.m_orderData[i]["room"] << "  预约时间段: " << (of.m_orderData[i]["time"] == "1" ? "上午" : "下午") << "  预约日期: 周" << of.m_orderData[i]["date"] << "  预约学生学号: " << of.m_orderData[i]["S_id"] << "  预约学生姓名: " << of.m_orderData[i]["S_name"] ;
		if (of.m_orderData[i]["status"] == "1")
		{
			cout << "  状态: 审核中" << endl;
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			cout << "  状态: 已预约" << endl;
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			cout << "  状态: 预约失败" << endl;
		}
		else
		{
			cout << "  状态: 取消预约" << endl;
		}
	}
}

void Students::cancelOrder()//取消预约
{
	OrderFile of;
	if (of.m_num == 0)
	{
		cout << "暂无预约记录!" << endl;
		return;
	}
	cout << "注意: 只有审核中或预约成功的记录才能取消!请选择要取消的记录:" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_num; i++)
	{
		if (this->m_ID == of.m_orderData[i]["S_id"])
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << " " << "机房编号: " << of.m_orderData[i]["room"] << " 预约时间: " << (of.m_orderData[i]["time"] == "1" ? "上午" : "下午") << " 预约日期: 周";
				cout << of.m_orderData[i]["date"] << " 状态: " << (of.m_orderData[i]["status"] == "1" ? "审核中" : "预约成功") << endl;
			}
		}
	}
	int select = 0;
	{
		while (1)
		{
			cin >> select;
			if (select >= 1 && select <= index)
			{
				of.m_orderData[v[select - 1]]["status"] = "0";  // 取消预约
				of.updateOrder();
				cout << "取消预约成功!" << endl;
				break;
			}
			else
			{
				cout << "请选择正确的选项!" << endl;
				continue;
			}
		}
	}
}


