#include "Students.h"

Students::Students()//Ĭ�Ϲ���
{

}

void Students::initComputerRoom()//��ʼ�����������
{
	vComputerRooms.clear();
	ifstream ifs;
	ComputerRoom tempComputerRoom = ComputerRoom();
	ifs.open(COMPUTER_FILE, ios::in);
	while (ifs >> tempComputerRoom.m_roomID && ifs >> tempComputerRoom.m_MaxCapacity && ifs >> tempComputerRoom.m_AvailableMachines) //��ȡ������Ϣ�����뵽vector��
	{
		vComputerRooms.push_back(tempComputerRoom);  // ���뵽vector��
	}
	ifs.close();
}

Students::Students(string id, string name, string pwd)//�вι���
{
	this->m_Name = name;
	this->m_ID = id;
	this->m_Password = pwd;
}

void Students::openMenu()//ѧ���˵�
{
	cout << "��ӭѧ���û� : " << this->m_Name << " ��½!" << endl;
	cout << "                _______________________________________" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              1.����ԤԼ               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              2.�鿴�ҵ�ԤԼ           \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              3.�鿴����ԤԼ           \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              4.ȡ��ԤԼ               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              0.ע����½               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "                ```````````````````````````````````````" << endl;
	this->initComputerRoom();
}

void Students::applyOrder()//����ԤԼ
{
	cout << "�����ɹ�ԤԼʹ�õ�ʱ��Ϊ��һ~����" << endl;
	cout << "��ѡ����ҪԤԼ��ʱ��: " << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
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
			cout << "��ѡ����ȷ��ʱ��!" << endl;
			continue;
		}
	}
	cout << "��ѡ������ԤԼ��ʱ���:" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
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
			cout << "��ѡ����ȷ��ʱ���!" << endl;
			continue;
		}
		if (time == 1 || time == 2)
		{
			break;
		}
	}
	cout << "��ѡ����ҪԤԼʹ�õĻ���:" << endl;
	for_each
	(
		vComputerRooms.begin(), vComputerRooms.end(), [](ComputerRoom room)
		{
			cout << left << "�������: " << room.m_roomID << "�����������: " << setw(5) << room.m_MaxCapacity << "������ǰ�����豸����: " << room.m_AvailableMachines << endl;
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
			cout << "��ѡ����ȷ��ѡ��!" << endl;
			continue;
		}
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app); // ׷��ģʽ���ļ�
	ofs << "room:" << room << " " << "time:" << time << " " << "date:" << data << " " << "S_id:" << this->m_ID << " " << "S_name:" << this->m_Name << " " << "status:" << 1 << endl;
	ofs.close();
	cout << "ԤԼ�ɹ�!��ǰ���������..." << endl;
}

void Students::showMyOrder()//�鿴�ҵ�ԤԼ
{
	OrderFile of;
	if (of.m_num == 0) // û��ԤԼ��¼
	{
		cout << "����ԤԼ��¼!" << endl;
		return;
	}
	cout << "��������ԤԼ��¼:" << endl;
	for (int i = 0; i < of.m_num; i++)
	{
		if (this->m_ID == of.m_orderData[i]["S_id"]) // �ҵ���ѧ����ԤԼ��¼
		{
			cout << "ԤԼ������: " << of.m_orderData[i]["room"];
			cout << "  ԤԼʱ���: " << (of.m_orderData[i]["time"] == "1" ? "����" : "����");
			cout << "  ԤԼ����: ��" << of.m_orderData[i]["date"];
			string status = "  ״̬: ";
			// ״̬: 0-ȡ��ԤԼ 1-����� 2-��ԤԼ -1 ԤԼʧ��
			{
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "��ԤԼ";
				}
				else if (of.m_orderData[i]["status"] == "-1")
				{
					status += "ԤԼʧ��";
				}
				else
				{
					status += "ȡ��ԤԼ";
				}
			}
			cout << status << endl;
		}
	}
}

void Students::showAllOrder()//�鿴����ԤԼ
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
		cout << i + 1 << " " << "������: " << of.m_orderData[i]["room"] << "  ԤԼʱ���: " << (of.m_orderData[i]["time"] == "1" ? "����" : "����") << "  ԤԼ����: ��" << of.m_orderData[i]["date"] << "  ԤԼѧ��ѧ��: " << of.m_orderData[i]["S_id"] << "  ԤԼѧ������: " << of.m_orderData[i]["S_name"] ;
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

void Students::cancelOrder()//ȡ��ԤԼ
{
	OrderFile of;
	if (of.m_num == 0)
	{
		cout << "����ԤԼ��¼!" << endl;
		return;
	}
	cout << "ע��: ֻ������л�ԤԼ�ɹ��ļ�¼����ȡ��!��ѡ��Ҫȡ���ļ�¼:" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_num; i++)
	{
		if (this->m_ID == of.m_orderData[i]["S_id"])
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << " " << "�������: " << of.m_orderData[i]["room"] << " ԤԼʱ��: " << (of.m_orderData[i]["time"] == "1" ? "����" : "����") << " ԤԼ����: ��";
				cout << of.m_orderData[i]["date"] << " ״̬: " << (of.m_orderData[i]["status"] == "1" ? "�����" : "ԤԼ�ɹ�") << endl;
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
				of.m_orderData[v[select - 1]]["status"] = "0";  // ȡ��ԤԼ
				of.updateOrder();
				cout << "ȡ��ԤԼ�ɹ�!" << endl;
				break;
			}
			else
			{
				cout << "��ѡ����ȷ��ѡ��!" << endl;
				continue;
			}
		}
	}
}


