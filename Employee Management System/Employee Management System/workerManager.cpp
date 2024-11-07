#include"workerManager.h"
#include<iostream>
using namespace std;

// ְ��������Ĺ��캯��
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
	cout << "ְ������Ϊ:" << num << "��" << endl;
	this->m_EmpNum = num;
	this->m_EmpArr = new Worker * [this->m_EmpNum];
	this->init_Emp();
}

// ��ʾ�˵�
void WorkerManager::showMenu()
{
	cout << "-----------------------------------" << endl;
	cout << "|       ��ӭʹ��ְ������ϵͳ!     |" << endl;
	cout << "|          1.����ְ����Ϣ         |" << endl;
	cout << "|          2.��ʾְ����Ϣ         |" << endl;
	cout << "|          3.ɾ����ְְ��         |" << endl;
	cout << "|          4.�޸�ְ����Ϣ         |" << endl;
	cout << "|          5.����ְ����Ϣ         |" << endl;
	cout << "|          6.���ձ������         |" << endl;
	cout << "|          7.�����������         |" << endl;
	cout << "|          0.�˳��������         |" << endl;
	cout << "-----------------------------------" << endl;
}

// ���ְ����Ϣ
void WorkerManager::addEmp()
{
	cout << "���������ְ��������:" << endl;
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
			cout << "�������" << i+1 << "����ְ���ı��:" << endl;
			cin >> id;
			int index = this->IsExist(id);
			if (index != -1)
			{
				cout << "�ñ���Ѵ���,����������!" << endl;
				i--;
				continue;
			}
			cout << "�������" << i+1 << "����ְ��������:" << endl;
			cin >> name;
			cout << "��ѡ���" << i+1 << "����ְ���ĸ�λ:" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
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
				cout << "�������,�����������λ��Ϣ!" << endl;
				i--;
				continue;
			}
			if (worker != NULL)
			{
				newSpace[this->m_EmpNum + i] = worker;
			}
			else
			{
				cout << "����ְ��ʧ�ܣ��޷���Ӹ�ְ��!" << endl;
			}
		}
		delete[] this->m_EmpArr;
		this->m_EmpArr = newSpace;
		this->m_EmpNum = newSize;
		this->save();
		this->FileIsEmpty = false;
		cout << "�ɹ����" << addnum << "��Ա��!" << endl;
	}
	else
	{
		cout << "��������ȷ��ֵ!" << endl;
	}
}

// ����ְ����Ϣ���ļ�
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

// ��ȡְ������
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

// ��ʼ��ְ����Ϣ
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

// ��ʾְ����Ϣ
void WorkerManager::Show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���!" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArr[i]->showinfo();
		}
	}
}

// ���ְ���Ƿ����
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

// ɾ��ְ����Ϣ
void WorkerManager::Del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���!" << endl;
	}
	else
	{
		cout << "��������Ҫɾ��ְ���ı��:" << endl;
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
			cout << "ɾ���ɹ�!" << endl;
		}
		else
		{
			cout << "�ñ��Ա��������!" << endl;
		}
	}
}

// �޸�ְ����Ϣ
void WorkerManager::Mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���!" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸�ְ���ı��:" << endl;
		int mod_id;
		cin >> mod_id;
		int index = this->IsExist(mod_id);
		if (index != -1)
		{
			cout << "�鵽ԭ����:" << this->m_EmpArr[index]->getDepartName() << "����,���Ϊ:" << this->m_EmpArr[index]->m_ID << "��Ա��: " << this->m_EmpArr[index]->m_Name << endl;
			int new_id = 0;
			delete this->m_EmpArr[index];
			string new_name = "";
			int new_dpid = 0;
			cout << "�������޸ĺ�ĸ�ְ���ı��:" << endl;
			cin >> new_id;
			cout << "�������޸ĺ�ĸ�ְ��������:" << endl;
			cin >> new_name;
			cout << "��ѡ���޸ĺ�ĸ�ְ���ĸ�λ:" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
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
				cout << "�������,��ѡ����ȷ�ĸ�λ��Ϣ!" << endl;
				return;
			}
			this->m_EmpArr[index] = worker;
			this->save();
			cout << "�޸ĳɹ�!" << endl;
		}
		else
		{
			cout << "�ñ��Ա��������!" << endl;
		}
	}
}

// ����ְ��
void WorkerManager::Search_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���!" << endl;
	}
	else
	{
		cout << "��ѡ����ҵķ�ʽ:" << endl;
		cout << "1.����Ų���" << endl;
		cout << "2.����������" << endl;
		int search_type;
		cin >> search_type;
		if (search_type == 1)
		{
			int search_id;
			cout << "��������Ҫ���ҵ�ְ���ı��:" << endl;
			cin >> search_id;
			int index = this->IsExist(search_id);
			if (index != -1)
			{
				cout << "�鵽���Ϊ:" << this->m_EmpArr[index]->m_ID << "��Ա��: " << this->m_EmpArr[index]->m_Name << "����������Ϊ:" << this->m_EmpArr[index]->getDepartName() << "����" << endl;
			}
			else
			{
				cout << "�ñ��Ա��������!" << endl;
			}
		}
		else if (search_type == 2)
		{
			string search_name;
			cout << "��������Ҫ���ҵ�ְ��������:" << endl;
			cin >> search_name;
			bool found = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (m_EmpArr[i]->m_Name == search_name)
				{
					cout << "�鵽���Ϊ:" << this->m_EmpArr[i]->m_ID << "��Ա��: " << this->m_EmpArr[i]->m_Name << "����������Ϊ:" << this->m_EmpArr[i]->getDepartName() << "����" << endl;
					found = true;
					break;
				}
			}
			if (found == false)
			{
				cout << "������Ա��������!" << endl;
				return;
			}
		}
		else
		{
			cout << "�������,����������!" << endl;
			return;
		}

	}
}

// ����ְ����Ϣ
void WorkerManager::Sort_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���!" << endl;
	}
	else
	{
		cout <<"��ѡ������ķ�ʽ:" << endl;
		cout <<"1.��ְ�������������" << endl;
		cout <<"2.��ְ����Ž�������" << endl;
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
					cout << "�������,��ѡ����ȷ��ѡ��!" << endl;
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
		cout << "����ɹ�!" << endl;
		this->save();
		cout << "�Ƿ������鿴������ְ����Ϣ?" << endl;
		cout << "1.��" << endl;
		cout << "2.��" << endl;
		int show_type;
		cin >> show_type;
		if (show_type == 1)
		{
			this->Show_Emp();
		}
		else if (show_type == 2)
		{
			cout << "�����˳�����ϵͳ..." << endl;
			return;
		}
		else
		{
			cout << "��ѡ����ȷ��ѡ��!" << endl;
		}
	}
}

// ����ļ��е�����ְ����Ϣ
void WorkerManager::Clean_File()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ򲻴���!" << endl;
	}
	else
	{
		cout << "�Ƿ�ȷ���������ְ����Ϣ?" << endl;
		cout << "1.��" << endl;
		cout << "2.��" << endl;
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
				cout << "��ճɹ�!" << endl;
			}
		}
		else if (clear_type == 2)
		{
			cout << "���ڷ���..." << endl;
		}
		else
		{
			cout << "��ѡ����ȷ��ѡ��!" << endl;
		}
	}
}

// �˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "�˳��ɹ�,��ӭ�´�ʹ��!" << endl;
	exit(0);
}

// ְ�����������������
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
