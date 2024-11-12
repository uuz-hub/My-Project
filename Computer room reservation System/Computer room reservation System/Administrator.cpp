#include "Administrator.h"

Administrator::Administrator()//Ĭ�Ϲ���
{

}

int countAvailableComputer(const vector<ComputerRoom> & rooms)//������û�������
{
	int machineCount = 0;  //���û�������
	for (vector<ComputerRoom>::const_iterator it = rooms.begin(); it != rooms.end(); it++)
	{
		machineCount += it->m_AvailableMachines;
	}
	return machineCount;
}

bool Administrator::checkRepeat(string id, int type)
{
	if (type == 1)  //���ѧ��ID�Ƿ��ظ�
	{
		for (vector<Students>::iterator it = vStudents.begin(); it != vStudents.end(); it++)  
		{
			if (id == it->m_ID)
			{
				return true;
			}
		}
	}
	else if (type == 2)  //����ʦID�Ƿ��ظ�
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

void Administrator::initComputerRoom() //��ʼ��������Ϣ
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
	cout << "��ǰ���û�������Ϊ: " << vComputerRooms.size() << "  ��ǰ���û�������Ϊ: "  << countAvailableComputer(vComputerRooms) << endl;
}

void Administrator::initVector()   //��ʼ��ѧ���ͽ�ʦ��Ϣ
{
	vStudents.clear();
	vTeachers.clear();
	ifstream ifs;
	Students tempStudent;
	ifs.open(STUDENT_FILE, ios::in);
	while (ifs >> tempStudent.m_ID && ifs >> tempStudent.m_Name && ifs >> tempStudent.m_Password) //��ȡѧ����Ϣ�����뵽vector��
	{
		vStudents.push_back(tempStudent);
	}
	cout << "��ǰϵͳ��ѧ������Ϊ: " << vStudents.size() << endl;
	ifs.close();
	Teacher tempTeacher;
	ifs.open(TEACHER_FILE, ios::in);
	while (ifs >> tempTeacher.m_T_ID && ifs >> tempTeacher.m_Name && ifs >> tempTeacher.m_Password)  //��ȡ��ʦ��Ϣ�����뵽vector��
	{
		vTeachers.push_back(tempTeacher);
	}
	cout << "��ǰϵͳ�н�ʦ����Ϊ: " << vTeachers.size() << endl;
	ifs.close();
}

Administrator::Administrator(string name, string password)//�вι���(����,����)
{
	this->m_Name = name;
	this->m_Password = password;
}

void Administrator::openMenu()//����Ա�˵�
{
	cout << "��ӭ����Ա: " << this->m_Name << " ��½!" << endl;
	cout << "                _______________________________________" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              1.����˺�               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              2.�鿴�˺�               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              3.�鿴������Ϣ           \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              4.���ԤԼ��¼           \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "               |              0.ע����½               \\" << endl;
	cout << "               |                                       \\" << endl;
	cout << "                ```````````````````````````````````````" << endl;
	this->initVector();
	this->initComputerRoom();
}

void Administrator::addAccount()//����˺�
{
	string FileName;
	int select;
	ofstream ofs;
	string errorMsg;
	cout << "��ѡ������˺ŵ����:" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;
	while (1)
	{
		cin >> select;
		if (select == 1) //���ѧ��
		{
			FileName = STUDENT_FILE;
			cout << "������ѧ��:" << endl;
			errorMsg = "ѧ���Ѵ���!";
			break;
		}
		else if (select == 2) //��ӽ�ʦ
		{
			FileName = TEACHER_FILE;
			cout << "�����빤��:" << endl;
			errorMsg = "�����Ѵ���!";
			break;
		}
		else
		{
			cout << "��ѡ����ȷ��ѡ��!" << endl;
			continue;
		}
	}
	ofs.open(FileName, ios::out | ios::app);
	string id;
	string name;
	string password;
	while (1) //��������ID�Ƿ��ظ�
	{
		cin >> id;
		if (checkRepeat(id, select))
		{
			cout << errorMsg << endl;
			return;
		}
		break;
	}
	cout << "�������û���:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> password;
	ofs << id << " " << name << " " << password << endl;
	ofs.close();
	cout << "����˻��ɹ�!" << endl;
}

void Administrator::showAccount()//�鿴�˺�
{
	cout << "��ѡ����Ҫ�鿴�˺ŵ�����:" << endl;
	cout << "1.�鿴���е�ѧ��" << endl;
	cout << "2.�鿴���еĽ�ʦ" << endl;
	int select;
	while (1)
	{
		cin >> select;
		switch (select)
		{
		case 1:
			for_each
			(
				vStudents.begin(), vStudents.end(), [](Students s) //ʹ��lambda���ʽ��������ѧ����Ϣ�����
				{
					cout << left <<  "ѧ��: " << setw(10) << s.m_ID  << "�û���: " << setw(15) << s.m_Name << "����: " <<  setw(15) <<s.m_Password << endl;
				}
			);
			return;
		case 2:
			for_each
			(
				vTeachers.begin(), vTeachers.end(), [](Teacher t) //ʹ��lambda���ʽ�������н�ʦ��Ϣ�����
				{
					cout << left << "����: " << setw(10) << t.m_T_ID << "�û���: " << setw(15) << t.m_Name << "����: " << setw(15) << t.m_Password << endl;
				}
			);
			return;
		default:
			cout << "��ѡ����ȷ��ѡ��!" << endl;
			continue;
		}
	}
}

void Administrator::showComputerRoom()//�鿴������Ϣ
{
	cout << "��ǰ���л�����Ϣ����:" << endl;
	for_each
	(
		vComputerRooms.begin(), vComputerRooms.end(), [](ComputerRoom cpr)
		{
			cout << left << "�������: " << cpr.m_roomID << "  �������: " << setw(5) << cpr.m_MaxCapacity << "��ǰ�����豸��: " << cpr.m_AvailableMachines << endl;
		}
	);
}

void Administrator::clearRecord()//���ԤԼ��¼
{
	cout << "ȷ��Ҫ�������ԤԼ��¼��?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	int select;
	while (1)
	{
		cin >> select;
		if (select == 1)
		{
			ofstream ofs;
			ofs.open(ORDER_FILE, ios::trunc);
			ofs.close();
			cout << "ԤԼ��¼�����!" << endl;
			return;
		}
		else if (select == 2)
		{
			cout << "������ȡ��!" << endl;
			cout << "���ڷ��ز�������..." << endl;
			return;
		}
		else
		{
			cout << "��ѡ����ȷ��ѡ��!" << endl;
			continue;
		}
	}
}

