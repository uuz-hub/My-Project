#include<iostream>
#include<string>
using namespace std;

const int MAX = 1000; // 定义通讯录最大容量

// 联系人结构体
struct Person 
{
	string name; // 姓名
	int sex; // 性别（1：男，2：女）
	int age; // 年龄
	string number; // 电话号码
	string address; // 地址
};

// 通讯录结构体
struct AddressBook 
{
	struct Person personArr[MAX]; // 存储联系人数组
	int size; // 当前联系人数量
};

// 计算电话号码的位数
int countDigits(const string& phoneNumber)
{
	return phoneNumber.length();
}

// 显示主菜单
void showMenu()
{
	cout << "  ----------------" << endl;
	cout << "||  1.添加联系人  ||" << endl;
	cout << "||  2.显示联系人  ||" << endl;
	cout << "||  3.删除联系人  ||" << endl;
	cout << "||  4.查找联系人  ||" << endl;
	cout << "||  5.修改联系人  ||" << endl;
	cout << "||  6.清空联系人  ||" << endl;
	cout << "||  0.退出通讯录  ||" << endl;
	cout << "  ----------------" << endl;
};

// 添加联系人
void addPerson(AddressBook* abs)
{
	if (abs->size == MAX) // 检查通讯录是否已满
	{
		cout << "通讯录已满,无法继续添加!请清理空间后重试!" << endl;
		return;
	}
	else
	{
		string name;
		unsigned int sex, age;
		string number;
		string address;

		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArr[abs->size].name = name; // 记录姓名

		cout << "请选择性别:" << endl;
		cout << "1→男   2→女" << endl;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) // 确保性别输入正确
			{
				abs->personArr[abs->size].sex = sex; // 记录性别
				break;
			}
			cout << "请选择正确的选项!" << endl;
		}

		while (1)
		{
			cout << "请输入年龄:" << endl;
			cin >> age;
			if (age >= 100 || age < 0) // 检查年龄输入有效性
			{
				cout << "请输入正确的年龄!" << endl;
				continue;
			}
			break;
		}
		abs->personArr[abs->size].age = age; // 记录年龄

		while (1)
		{
			cout << "请输入电话号码:" << endl;
			cin >> number;
			if (countDigits(number) != 11) // 检查电话号码位数
			{
				cout << "请输入正确的电话号码!" << endl;
				continue;
			}
			break;
		}
		abs->personArr[abs->size].number = number; // 记录号码

		cout << "请输入地址:" << endl;
		cin >> address;
		abs->personArr[abs->size].address = address; // 记录地址

		abs->size++; // 更新联系人数量
		cout << "添加成功!" << endl;
	}
}

// 显示所有联系人
void showPerson(AddressBook* abs)
{
	if (abs->size == 0) // 检查通讯录是否为空
	{
		cout << "当前通讯录为空!" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++) // 遍历并显示所有联系人信息
		{
			cout << "姓名:" << abs->personArr[i].name 
			     << "  性别:" << (abs->personArr[i].sex == 1 ? "男" : "女") 
			     << "  年龄:" << abs->personArr[i].age 
			     << "  电话:" << abs->personArr[i].number 
			     << "  地址:" << abs->personArr[i].address << endl;
		}
	}
}

// 检查联系人是否存在，返回位置
int isExist(AddressBook* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArr[i].name == name) // 若找到联系人
		{
			return i; // 返回联系人位置
		}
	}
	return -1; // 未找到联系人
}

// 删除联系人
void deletePerson(AddressBook* abs)
{
	cout << "请输入需要删除的联系人的姓名:" << endl;
	string name_delete;
	cin >> name_delete;

	int index = isExist(abs, name_delete);
	if (index != -1) // 检测联系人是否存在
	{
		for (int i = index; i < abs->size - 1; i++) // 移动后续联系人
		{
			abs->personArr[i] = abs->personArr[i + 1];
		}
		abs->size--; // 更新联系人数量
		cout << "删除成功!" << endl;
	}
	else
	{
		cout << "查无此人" << endl; // 未找到联系人
	}
}

// 查找联系人
void secrchPerson(AddressBook* abs)
{
	cout << "请输入需要查找的联系人姓名:" << endl;
	string name_secrch;
	cin >> name_secrch;

	int index = isExist(abs, name_secrch);
	if (index != -1) // 检测联系人是否存在
	{
		cout << "姓名:" << abs->personArr[index].name 
		     << "  性别:" << abs->personArr[index].sex 
		     << "  年龄:" << abs->personArr[index].age 
		     << "  电话:" << abs->personArr[index].number 
		     << "  住址:" << abs->personArr[index].address << endl;
	}
	else
	{
		cout << "查无此人!" << endl; // 未找到联系人
	}
}

// 修改联系人信息
void modifyPerson(AddressBook* abs)
{
	cout << "请输入需要修改信息的联系人姓名:" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) // 若联系人存在
	{
		string name_modify;
		int sex_modify;
		int age_modify;
		string number_modify;
		string address_modify;

		cout << "请输入姓名:" << endl;
		cin >> name_modify;
		abs->personArr[ret].name = name_modify; // 修改姓名

		cout << "请输入性别:" << endl;
		cout << "1→男   2→女" << endl;
		while (1)
		{
			cin >> sex_modify;
			if (sex_modify == 1 || sex_modify == 2) // 确保性别输入正确
			{
				abs->personArr[ret].sex = sex_modify; // 修改性别
				break;
			}
			cout << "请选择正确的选项!" << endl;
		}

		while (1)
		{
			cout << "请输入年龄:" << endl;
			cin >> age_modify;
			if (age_modify >= 100 || age_modify < 0) // 检查年龄输入有效性
			{
				cout << "请输入正确的年龄!" << endl;
				continue;
			}
			break;
		}
		abs->personArr[ret].age = age_modify; // 修改年龄

		while (1)
		{
			cout << "请输入电话号码:" << endl;
			cin >> number_modify;
			if (countDigits(number_modify) != 11) // 检查电话号码位数
			{
				cout << "请输入正确的电话号码!" << endl;
				continue;
			}
			break;
		}
		abs->personArr[ret].number = number_modify; // 修改电话号码

		cout << "请输入地址:" << endl;
		cin >> address_modify;
		abs->personArr[ret].address = address_modify; // 修改地址

		cout << "修改成功!" << endl;
	}
	else
	{
		cout << "查无此人!" << endl; // 未找到联系人
	}
}

// 清空所有联系人
void deleteAllPerson(AddressBook* abs)
{
	cout << "确定这样做吗?这将会清空所有数据" << endl;
	cout << "1→确定  2→返回" << endl;
	int choose;
	cin >> choose;
	if (choose == 1) // 如果选择确定
	{
		abs->size = 0; // 清空联系人数量
		cout << "所有数据已清空!" << endl;
	}
	return;
}

// 主函数
int main()
{
	AddressBook ABS; // 创建通讯录
	ABS.size = 0; // 初始化联系人数量
	int choose;

	while (1)
	{
		showMenu(); // 显示菜单
		cin >> choose;
		switch (choose)
		{
		case 1:
			addPerson(&ABS); // 添加联系人
			break;
		case 2:
			showPerson(&ABS); // 显示联系人
			break;
		case 3:
			deletePerson(&ABS); // 删除联系人
			break;
		case 4:
			secrchPerson(&ABS); // 查找联系人
			break;
		case 5:
			modifyPerson(&ABS); // 修改联系人
			break;
		case 6:
			deleteAllPerson(&ABS); // 清空联系人
			break;
		case 0:
			cout << "退出成功,欢迎下次使用!" << endl; // 退出程序
			return 0;
		default:
			cout << "请输入正确的选项!" << endl; // 输入错误，提示重新输入
			system("pause");
			system("cls"); // 清屏
			continue;
		}
		system("pause"); // 暂停
		system("cls"); // 清屏
	}

	return 0; // 程序结束
}