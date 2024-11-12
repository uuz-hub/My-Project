#include "Teacher.h"

Teacher::Teacher()//默认构造
{

}

Teacher::Teacher(string id, string name, string pwd)//有参构造(工号,姓名,密码)
{
	this->m_Name = name;
	this->m_T_ID = id;
	this->m_Password = pwd;
}

void Teacher::openMenu()//教师端菜单
{
	cout << "欢迎教师: " << this->m_Name << " 登陆!" << endl;
	cout << "                _______________________________________" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              1.查看所有预约           \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              2.审核预约               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              0.注销登陆               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "                ```````````````````````````````````````" << endl;
}

void Teacher::showAllOrder()//查看所有预约
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
		cout << i + 1 << " " << "机房号: " << of.m_orderData[i]["room"] << "  预约时间段: " << (of.m_orderData[i]["time"] == "1" ? "上午" : "下午") << "  预约日期: 周" << of.m_orderData[i]["date"] << "  预约学生学号: " << of.m_orderData[i]["S_id"] << "  预约学生姓名: " << of.m_orderData[i]["S_name"];
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

void Teacher::examOrder()//审核预约
{
	OrderFile of;
	if (of.m_num == 0)
	{
		cout << "暂无预约记录!" << endl;
		return;
	}
	int index = 0;
	vector<int>v;
	cout << "所有需审核的预约记录如下: " << endl;
	for (int i = 0; i < of.m_num; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << " ";
			cout << " 机房编号: " << of.m_orderData[i]["room"];
			cout << " 预约时间: 周" << (of.m_orderData[i]["time"] == "1" ? "上午" : "下午");
			cout << " 预约日期: " << of.m_orderData[i]["date"];
			cout << " 学生学号: " << of.m_orderData[i]["S_id"];
			cout << " 学生姓名: " << of.m_orderData[i]["S_name"];
			cout << " 机房编号: " << of.m_orderData[i]["room"];
			cout << " 状态: 审核中" << endl;
		}
	}
	cout << "请输入需要审核的预约序号: " << endl;
	int select = 0;
	while (1)
	{
		cin >> select;
		if (select > 0 || select <= v.size())
		{
			cout << "请选择审核的结果:" << endl;
			cout << "1.通过" << endl;
			cout << "2.拒绝" << endl;
			int result = 0;
			while (1)
			{
				cin >> result;
				switch (result)
				{
				case 1:
					of.m_orderData[v[select -1]]["status"] = "2";
					cout << "审核成功, 预约已通过!" << endl;
					of.updateOrder();
					return;
				case 2:
					of.m_orderData[v[select -1]]["status"] = "-1";
					cout << "审核成功,预约已取消!" << endl;
					of.updateOrder();
					return;
				default:
					cout << "请选择正确的选项!" << endl;
					continue;
				}
			}
		}
		else
		{	
			cout << "请输入正确的序号!" << endl;
			continue;
		}
	}
}

