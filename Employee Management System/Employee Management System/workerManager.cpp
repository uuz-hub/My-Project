#include"workerManager.h"
#include<iostream>
using namespace std;

// 职工管理类的构造函数
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		this->m_EmpNum = 0;
		this->m_EmpArr = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_EmpNum = 0;
		this->m_EmpArr = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	cout << "职工人数为:" << num << "人" << endl;
	this->m_EmpNum = num;
	this->m_EmpArr = new Worker * [this->m_EmpNum];
	this->init_Emp();
}

// 显示菜单
void WorkerManager::showMenu()
{
	cout << "-----------------------------------" << endl;
	cout << "|       欢迎使用职工管理系统!     |" << endl;
	cout << "|          1.增加职工信息         |" << endl;
	cout << "|          2.显示职工信息         |" << endl;
	cout << "|          3.删除离职职工         |" << endl;
	cout << "|          4.修改职工信息         |" << endl;
	cout << "|          5.查找职工信息         |" << endl;
	cout << "|          6.按照编号排序         |" << endl;
	cout << "|          7.清空所有数据         |" << endl;
	cout << "|          0.退出管理程序         |" << endl;
	cout << "-----------------------------------" << endl;
}

// 添加职工信息
void WorkerManager::addEmp()
{
	cout << "请输入添加职工的数量:" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		int newSize = this->m_EmpNum + addnum;
		Worker** newSpace = new Worker * [newSize];
		if ((this->m_EmpArr) != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArr[i];
			}
		}
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int dpid;
			cout << "请输入第" << i+1 << "个新职工的编号:" << endl;
			cin >> id;
			int index = this->IsExist(id);
			if (index != -1)
			{
				cout << "该编号已存在,请重新输入!" << endl;
				i--;
				continue;
			}
			cout << "请输入第" << i+1 << "个新职工的姓名:" << endl;
			cin >> name;
			cout << "请选择第" << i+1 << "个新职工的岗位:" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.CEO" << endl;
			cin >> dpid;
			Worker* worker = NULL;
			switch (dpid)
			{
			case 1:	
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "输入错误,请重新输入岗位信息!" << endl;
				i--;
				continue;
			}
			if (worker != NULL)
			{
				newSpace[this->m_EmpNum + i] = worker;
			}
			else
			{
				cout << "创建职工失败，无法添加该职工!" << endl;
			}
		}
		delete[] this->m_EmpArr;
		this->m_EmpArr = newSpace;
		this->m_EmpNum = newSize;
		this->save();
		this->FileIsEmpty = false;
		cout << "成功添加" << addnum << "名员工!" << endl;
	}
	else
	{
		cout << "请输入正确的值!" << endl;
	}
}

// 保存职工信息到文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArr[i]->m_ID << "  " << this->m_EmpArr[i]->m_Name << "  " << this->m_EmpArr[i]->m_departID << endl;
	}
	ofs.close();
}

// 获取职工人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dpid;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dpid)
	{
		num++;
	}
	return num;
}

// 初始化职工信息
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dpid;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dpid)
	{
		Worker* worker = NULL;
		switch (dpid)
		{
		case 1:
			worker = new Employee(id, name, 1);
			break;
		case 2:
			worker = new Manager(id, name, 2);
			break;
		case 3:
			worker = new Boss(id, name, 3);
			break;
		default:
			break;
		}
		this->m_EmpArr[index] = worker;
		index++;
	}
	ifs.close();
}

// 显示职工信息
void WorkerManager::Show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件为空或不存在!" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArr[i]->showinfo();
		}
	}
}

// 检查职工是否存在
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArr[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

// 删除职工信息
void WorkerManager::Del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件为空或不存在!" << endl;
	}
	else
	{
		cout << "请输入需要删除职工的编号:" << endl;
		int del_id;
		cin >> del_id;
		int index = this->IsExist(del_id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArr[i] = this->m_EmpArr[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功!" << endl;
		}
		else
		{
			cout << "该编号员工不存在!" << endl;
		}
	}
}

// 修改职工信息
void WorkerManager::Mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件为空或不存在!" << endl;
	}
	else
	{
		cout << "请输入需要修改职工的编号:" << endl;
		int mod_id;
		cin >> mod_id;
		int index = this->IsExist(mod_id);
		if (index != -1)
		{
			cout << "查到原属于:" << this->m_EmpArr[index]->getDepartName() << "部门,编号为:" << this->m_EmpArr[index]->m_ID << "的员工: " << this->m_EmpArr[index]->m_Name << endl;
			int new_id = 0;
			delete this->m_EmpArr[index];
			string new_name = "";
			int new_dpid = 0;
			cout << "请输入修改后的该职工的编号:" << endl;
			cin >> new_id;
			cout << "请输入修改后的该职工的姓名:" << endl;
			cin >> new_name;
			cout << "请选择修改后的该职工的岗位:" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.CEO"	 << endl;
			cin >> new_dpid;
			Worker* worker = NULL;
			switch (new_dpid)
			{
			case 1:
				worker = new Employee(new_id, new_name, new_dpid);
				break;
			case 2:
				worker = new Manager(new_id, new_name, new_dpid);
				break;
			case 3:
				worker = new Boss(new_id, new_name, new_dpid);
				break;
			default:
				cout << "输入错误,请选择正确的岗位信息!" << endl;
				return;
			}
			this->m_EmpArr[index] = worker;
			this->save();
			cout << "修改成功!" << endl;
		}
		else
		{
			cout << "该编号员工不存在!" << endl;
		}
	}
}

// 查找职工
void WorkerManager::Search_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件为空或不存在!" << endl;
	}
	else
	{
		cout << "请选择查找的方式:" << endl;
		cout << "1.按编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		int search_type;
		cin >> search_type;
		if (search_type == 1)
		{
			int search_id;
			cout << "请输入需要查找的职工的编号:" << endl;
			cin >> search_id;
			int index = this->IsExist(search_id);
			if (index != -1)
			{
				cout << "查到编号为:" << this->m_EmpArr[index]->m_ID << "的员工: " << this->m_EmpArr[index]->m_Name << "其所属部门为:" << this->m_EmpArr[index]->getDepartName() << "部门" << endl;
			}
			else
			{
				cout << "该编号员工不存在!" << endl;
			}
		}
		else if (search_type == 2)
		{
			string search_name;
			cout << "请输入需要查找的职工的姓名:" << endl;
			cin >> search_name;
			bool found = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (m_EmpArr[i]->m_Name == search_name)
				{
					cout << "查到编号为:" << this->m_EmpArr[i]->m_ID << "的员工: " << this->m_EmpArr[i]->m_Name << "其所属部门为:" << this->m_EmpArr[i]->getDepartName() << "部门" << endl;
					found = true;
					break;
				}
			}
			if (found == false)
			{
				cout << "该姓名员工不存在!" << endl;
				return;
			}
		}
		else
		{
			cout << "输入错误,请重新输入!" << endl;
			return;
		}

	}
}

// 排序职工信息
void WorkerManager::Sort_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件为空或不存在!" << endl;
	}
	else
	{
		cout <<"请选择排序的方式:" << endl;
		cout <<"1.按职工编号升序排序" << endl;
		cout <<"2.按职工编号降序排序" << endl;
		int sort_type;
		cin >> sort_type;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int MinOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (sort_type == 1)
				{
					if (this->m_EmpArr[j]->m_ID < this->m_EmpArr[MinOrMax]->m_ID)
					{
						MinOrMax = j;
					}
				}
				else if (sort_type == 2)
				{
					if (this->m_EmpArr[j]->m_ID > this->m_EmpArr[MinOrMax]->m_ID)
					{
						MinOrMax = j;
					}
				}
				else
				{
					cout << "输入错误,请选择正确的选项!" << endl;
					return;
				}
				if (i != MinOrMax)
				{
					Worker* temp = this->m_EmpArr[i];
					this->m_EmpArr[i] = this->m_EmpArr[MinOrMax];
					this->m_EmpArr[MinOrMax] = temp;
				}
			}
		}
		cout << "排序成功!" << endl;
		this->save();
		cout << "是否立即查看排序后的职工信息?" << endl;
		cout << "1.是" << endl;
		cout << "2.否" << endl;
		int show_type;
		cin >> show_type;
		if (show_type == 1)
		{
			this->Show_Emp();
		}
		else if (show_type == 2)
		{
			cout << "正在退出排序系统..." << endl;
			return;
		}
		else
		{
			cout << "请选择正确的选项!" << endl;
		}
	}
}

// 清空文件中的所有职工信息
void WorkerManager::Clean_File()
{
	if (this->FileIsEmpty)
	{
		cout << "文件为空或不存在!" << endl;
	}
	else
	{
		cout << "是否确认清空所有职工信息?" << endl;
		cout << "1.是" << endl;
		cout << "2.否" << endl;
		int clear_type;
		cin >> clear_type;
		if (clear_type == 1)
		{
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();
			if (this->m_EmpArr != NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArr[i] != NULL)
					{
						delete this->m_EmpArr[i];
						this->m_EmpArr[i] = NULL;
					}
				}
				delete[] this->m_EmpArr;
				this->m_EmpArr = NULL;
				this->m_EmpNum = 0;
				this->FileIsEmpty = true;
				cout << "清空成功!" << endl;
			}
		}
		else if (clear_type == 2)
		{
			cout << "正在返回..." << endl;
		}
		else
		{
			cout << "请选择正确的选项!" << endl;
		}
	}
}

// 退出系统
void WorkerManager::ExitSystem()
{
	cout << "退出成功,欢迎下次使用!" << endl;
	exit(0);
}

// 职工管理类的析构函数
WorkerManager::~WorkerManager()
{
	if ((this->m_EmpArr) != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArr[i] != NULL)
			{
				delete this->m_EmpArr[i];
				this->m_EmpArr[i] = NULL;
			}
		}
		delete[] this->m_EmpArr;
		this->m_EmpArr = NULL;
	}
}
