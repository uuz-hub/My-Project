#include "Teacher.h"

Teacher::Teacher()//Ĭ�Ϲ���
{

}

Teacher::Teacher(string id, string name, string pwd)//�вι���(����,����,����)
{
	this->m_Name = name;
	this->m_T_ID = id;
	this->m_Password = pwd;
}

void Teacher::openMenu()//��ʦ�˲˵�
{
	cout << "��ӭ��ʦ: " << this->m_Name << " ��½!" << endl;
	cout << "                _______________________________________" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              1.�鿴����ԤԼ           \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              2.���ԤԼ               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              0.ע����½               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "                ```````````````````````````````````````" << endl;
}

void Teacher::showAllOrder()//�鿴����ԤԼ
{
	OrderFile of;
	if (of.m_num == 0)
	{
		cout << "����ԤԼ��¼!" << endl;
		return;
	}
	cout << "����ԤԼ��¼����: " << endl;
	for (int i = 0; i < of.m_num; i++)
	{
		cout << i + 1 << " " << "������: " << of.m_orderData[i]["room"] << "  ԤԼʱ���: " << (of.m_orderData[i]["time"] == "1" ? "����" : "����") << "  ԤԼ����: ��" << of.m_orderData[i]["date"] << "  ԤԼѧ��ѧ��: " << of.m_orderData[i]["S_id"] << "  ԤԼѧ������: " << of.m_orderData[i]["S_name"];
		if (of.m_orderData[i]["status"] == "1")
		{
			cout << "  ״̬: �����" << endl;
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			cout << "  ״̬: ��ԤԼ" << endl;
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			cout << "  ״̬: ԤԼʧ��" << endl;
		}
		else
		{
			cout << "  ״̬: ȡ��ԤԼ" << endl;
		}
	}
}

void Teacher::examOrder()//���ԤԼ
{
	OrderFile of;
	if (of.m_num == 0)
	{
		cout << "����ԤԼ��¼!" << endl;
		return;
	}
	int index = 0;
	vector<int>v;
	cout << "��������˵�ԤԼ��¼����: " << endl;
	for (int i = 0; i < of.m_num; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << " ";
			cout << " �������: " << of.m_orderData[i]["room"];
			cout << " ԤԼʱ��: ��" << (of.m_orderData[i]["time"] == "1" ? "����" : "����");
			cout << " ԤԼ����: " << of.m_orderData[i]["date"];
			cout << " ѧ��ѧ��: " << of.m_orderData[i]["S_id"];
			cout << " ѧ������: " << of.m_orderData[i]["S_name"];
			cout << " �������: " << of.m_orderData[i]["room"];
			cout << " ״̬: �����" << endl;
		}
	}
	cout << "��������Ҫ��˵�ԤԼ���: " << endl;
	int select = 0;
	while (1)
	{
		cin >> select;
		if (select > 0 || select <= v.size())
		{
			cout << "��ѡ����˵Ľ��:" << endl;
			cout << "1.ͨ��" << endl;
			cout << "2.�ܾ�" << endl;
			int result = 0;
			while (1)
			{
				cin >> result;
				switch (result)
				{
				case 1:
					of.m_orderData[v[select -1]]["status"] = "2";
					cout << "��˳ɹ�, ԤԼ��ͨ��!" << endl;
					of.updateOrder();
					return;
				case 2:
					of.m_orderData[v[select -1]]["status"] = "-1";
					cout << "��˳ɹ�,ԤԼ��ȡ��!" << endl;
					of.updateOrder();
					return;
				default:
					cout << "��ѡ����ȷ��ѡ��!" << endl;
					continue;
				}
			}
		}
		else
		{	
			cout << "��������ȷ�����!" << endl;
			continue;
		}
	}
}

