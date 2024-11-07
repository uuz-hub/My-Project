#include<iostream>
#include<string>
using namespace std;

const int MAX = 1000; // ����ͨѶ¼�������

// ��ϵ�˽ṹ��
struct Person 
{
	string name; // ����
	int sex; // �Ա�1���У�2��Ů��
	int age; // ����
	string number; // �绰����
	string address; // ��ַ
};

// ͨѶ¼�ṹ��
struct AddressBook 
{
	struct Person personArr[MAX]; // �洢��ϵ������
	int size; // ��ǰ��ϵ������
};

// ����绰�����λ��
int countDigits(const string& phoneNumber)
{
	return phoneNumber.length();
}

// ��ʾ���˵�
void showMenu()
{
	cout << "  ----------------" << endl;
	cout << "||  1.�����ϵ��  ||" << endl;
	cout << "||  2.��ʾ��ϵ��  ||" << endl;
	cout << "||  3.ɾ����ϵ��  ||" << endl;
	cout << "||  4.������ϵ��  ||" << endl;
	cout << "||  5.�޸���ϵ��  ||" << endl;
	cout << "||  6.�����ϵ��  ||" << endl;
	cout << "||  0.�˳�ͨѶ¼  ||" << endl;
	cout << "  ----------------" << endl;
};

// �����ϵ��
void addPerson(AddressBook* abs)
{
	if (abs->size == MAX) // ���ͨѶ¼�Ƿ�����
	{
		cout << "ͨѶ¼����,�޷��������!������ռ������!" << endl;
		return;
	}
	else
	{
		string name;
		unsigned int sex, age;
		string number;
		string address;

		cout << "����������:" << endl;
		cin >> name;
		abs->personArr[abs->size].name = name; // ��¼����

		cout << "��ѡ���Ա�:" << endl;
		cout << "1����   2��Ů" << endl;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) // ȷ���Ա�������ȷ
			{
				abs->personArr[abs->size].sex = sex; // ��¼�Ա�
				break;
			}
			cout << "��ѡ����ȷ��ѡ��!" << endl;
		}

		while (1)
		{
			cout << "����������:" << endl;
			cin >> age;
			if (age >= 100 || age < 0) // �������������Ч��
			{
				cout << "��������ȷ������!" << endl;
				continue;
			}
			break;
		}
		abs->personArr[abs->size].age = age; // ��¼����

		while (1)
		{
			cout << "������绰����:" << endl;
			cin >> number;
			if (countDigits(number) != 11) // ���绰����λ��
			{
				cout << "��������ȷ�ĵ绰����!" << endl;
				continue;
			}
			break;
		}
		abs->personArr[abs->size].number = number; // ��¼����

		cout << "�������ַ:" << endl;
		cin >> address;
		abs->personArr[abs->size].address = address; // ��¼��ַ

		abs->size++; // ������ϵ������
		cout << "��ӳɹ�!" << endl;
	}
}

// ��ʾ������ϵ��
void showPerson(AddressBook* abs)
{
	if (abs->size == 0) // ���ͨѶ¼�Ƿ�Ϊ��
	{
		cout << "��ǰͨѶ¼Ϊ��!" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++) // ��������ʾ������ϵ����Ϣ
		{
			cout << "����:" << abs->personArr[i].name 
			     << "  �Ա�:" << (abs->personArr[i].sex == 1 ? "��" : "Ů") 
			     << "  ����:" << abs->personArr[i].age 
			     << "  �绰:" << abs->personArr[i].number 
			     << "  ��ַ:" << abs->personArr[i].address << endl;
		}
	}
}

// �����ϵ���Ƿ���ڣ�����λ��
int isExist(AddressBook* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArr[i].name == name) // ���ҵ���ϵ��
		{
			return i; // ������ϵ��λ��
		}
	}
	return -1; // δ�ҵ���ϵ��
}

// ɾ����ϵ��
void deletePerson(AddressBook* abs)
{
	cout << "��������Ҫɾ������ϵ�˵�����:" << endl;
	string name_delete;
	cin >> name_delete;

	int index = isExist(abs, name_delete);
	if (index != -1) // �����ϵ���Ƿ����
	{
		for (int i = index; i < abs->size - 1; i++) // �ƶ�������ϵ��
		{
			abs->personArr[i] = abs->personArr[i + 1];
		}
		abs->size--; // ������ϵ������
		cout << "ɾ���ɹ�!" << endl;
	}
	else
	{
		cout << "���޴���" << endl; // δ�ҵ���ϵ��
	}
}

// ������ϵ��
void secrchPerson(AddressBook* abs)
{
	cout << "��������Ҫ���ҵ���ϵ������:" << endl;
	string name_secrch;
	cin >> name_secrch;

	int index = isExist(abs, name_secrch);
	if (index != -1) // �����ϵ���Ƿ����
	{
		cout << "����:" << abs->personArr[index].name 
		     << "  �Ա�:" << abs->personArr[index].sex 
		     << "  ����:" << abs->personArr[index].age 
		     << "  �绰:" << abs->personArr[index].number 
		     << "  סַ:" << abs->personArr[index].address << endl;
	}
	else
	{
		cout << "���޴���!" << endl; // δ�ҵ���ϵ��
	}
}

// �޸���ϵ����Ϣ
void modifyPerson(AddressBook* abs)
{
	cout << "��������Ҫ�޸���Ϣ����ϵ������:" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) // ����ϵ�˴���
	{
		string name_modify;
		int sex_modify;
		int age_modify;
		string number_modify;
		string address_modify;

		cout << "����������:" << endl;
		cin >> name_modify;
		abs->personArr[ret].name = name_modify; // �޸�����

		cout << "�������Ա�:" << endl;
		cout << "1����   2��Ů" << endl;
		while (1)
		{
			cin >> sex_modify;
			if (sex_modify == 1 || sex_modify == 2) // ȷ���Ա�������ȷ
			{
				abs->personArr[ret].sex = sex_modify; // �޸��Ա�
				break;
			}
			cout << "��ѡ����ȷ��ѡ��!" << endl;
		}

		while (1)
		{
			cout << "����������:" << endl;
			cin >> age_modify;
			if (age_modify >= 100 || age_modify < 0) // �������������Ч��
			{
				cout << "��������ȷ������!" << endl;
				continue;
			}
			break;
		}
		abs->personArr[ret].age = age_modify; // �޸�����

		while (1)
		{
			cout << "������绰����:" << endl;
			cin >> number_modify;
			if (countDigits(number_modify) != 11) // ���绰����λ��
			{
				cout << "��������ȷ�ĵ绰����!" << endl;
				continue;
			}
			break;
		}
		abs->personArr[ret].number = number_modify; // �޸ĵ绰����

		cout << "�������ַ:" << endl;
		cin >> address_modify;
		abs->personArr[ret].address = address_modify; // �޸ĵ�ַ

		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "���޴���!" << endl; // δ�ҵ���ϵ��
	}
}

// ���������ϵ��
void deleteAllPerson(AddressBook* abs)
{
	cout << "ȷ����������?�⽫�������������" << endl;
	cout << "1��ȷ��  2������" << endl;
	int choose;
	cin >> choose;
	if (choose == 1) // ���ѡ��ȷ��
	{
		abs->size = 0; // �����ϵ������
		cout << "�������������!" << endl;
	}
	return;
}

// ������
int main()
{
	AddressBook ABS; // ����ͨѶ¼
	ABS.size = 0; // ��ʼ����ϵ������
	int choose;

	while (1)
	{
		showMenu(); // ��ʾ�˵�
		cin >> choose;
		switch (choose)
		{
		case 1:
			addPerson(&ABS); // �����ϵ��
			break;
		case 2:
			showPerson(&ABS); // ��ʾ��ϵ��
			break;
		case 3:
			deletePerson(&ABS); // ɾ����ϵ��
			break;
		case 4:
			secrchPerson(&ABS); // ������ϵ��
			break;
		case 5:
			modifyPerson(&ABS); // �޸���ϵ��
			break;
		case 6:
			deleteAllPerson(&ABS); // �����ϵ��
			break;
		case 0:
			cout << "�˳��ɹ�,��ӭ�´�ʹ��!" << endl; // �˳�����
			return 0;
		default:
			cout << "��������ȷ��ѡ��!" << endl; // ���������ʾ��������
			system("pause");
			system("cls"); // ����
			continue;
		}
		system("pause"); // ��ͣ
		system("cls"); // ����
	}

	return 0; // �������
}