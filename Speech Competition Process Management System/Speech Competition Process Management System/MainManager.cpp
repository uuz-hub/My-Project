#include "MainManager.h"  //管理系统核心文件
class myeach
{
public:
	bool operator()(int i)
	{
		cout << i << "  ";
		return true;	
	}
};

MainManager::MainManager()  //构造函数
{
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}

void MainManager::showMenu()  //显示菜单
{
	 cout << " ----------------------" << endl;
	 cout << "|   欢迎参加演讲比赛!  |" << endl;
	 cout << "|    1.开始演讲比赛    |" << endl;
	 cout << "|    2.查看往届记录    |" << endl;
	 cout << "|    3.清空比赛记录    |" << endl;
	 cout << "|    0.退出比赛程序    |" << endl;
	 cout << " ----------------------" << endl;
}  

void MainManager::exitSystem()  //退出系统
{
	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);
}  

void MainManager::initSpeech()  //初始化系统
{
	this->Index = 1;
	this->Round1.clear();
	this->Round2.clear();
	this->Victory.clear();
	this->m_speaker.clear();
	this->m_record.clear(); 
}

void MainManager::createSpeaker()  //创建演讲者
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		Speaker sp;
		string name = "选手";
		name += nameSeed[i];
		sp.m_name = name;

		this->Round1.push_back(i + 10001);
		this->m_speaker.insert(make_pair(i + 10001, sp));
	}
}

void MainManager::startSpeech()
{
	//第一轮比赛

	//抽签
	speechDraw();
	//比赛
	speechContest();
	//显示晋级结果
	showScore();
    //第二轮比赛
	this->Index++;
	//抽签
	speechDraw();
	//比赛
	speechContest();
	//记录最终结果
	showScore();
	//保存比赛记录
	saveRecord();
	cout << "本届比赛完毕!" << endl;
	//重置比赛
	//初始化容器和属性
	initSpeech();
	//重新创建演讲者
	createSpeaker();
	//重新加载记录
	loadRecord();
}

void MainManager::speechDraw() //抽签
{
	if (Index == 1)  //第一轮比赛
	{
		cout << "第  " << this->Index << "  轮比赛正在抽签" << endl;
		system("pause");
		cout << "----------------------------------" << endl;
		cout << "抽签后演讲顺序如下:" << endl;
		random_shuffle(Round1.begin(), Round1.end());
		for_each(Round1.begin(), Round1.end(), myeach());
		cout << endl;
	}
	else  //第二轮比赛
	{
		cout << "第  " << this->Index << "  轮比赛正在抽签" << endl;
		system("pause");
		cout << "--------------------------------------------" << endl;
		cout << "抽签后演讲顺序如下:" << endl;
		random_shuffle(Round2.begin(), Round2.end());
		for_each(Round2.begin(), Round2.end(), myeach());
		cout << endl;
	}
	cout << "----------------------------------" << endl;
	system("pause");
	cout << endl;
}

void MainManager::speechContest()
{
	multimap<double, int, greater<double> >groupScore; //记录每个组的得分
	cout << "第  " << this->Index << "  轮比赛正在进行" << endl;
	system("pause");
	int num = 0; //记录人员数 , 6个为一组
	vector<int>v_Src; //比赛人员容器
	if (Index == 1)  //第一轮比赛
	{
		v_Src = Round1;
	}
	else  //第二轮比赛
	{
		v_Src = Round2;
	}
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		deque<double>d;  //记录每个演讲者的得分
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; //随机生成60-100之间的分数
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		//平均分放入map容器
		this->m_speaker[*it].m_score[this->Index -1] = avg;
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第 " << num / 6 << " 组小组比赛情况如下:" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号: " << it->second << "  姓名: " << this->m_speaker[it->second].m_name << "  得分: " << this->m_speaker[it->second].m_score[this->Index - 1] << endl;
			}
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++,count++)
			{
				if (Index == 1)
				{
					Round2.push_back((*it).second);
				}
				else
				{
					Victory.push_back((*it).second);
				}
			}
			groupScore.clear();
		}
	}
	cout << "第" << this->Index << "轮比赛结束" << endl;
}

void MainManager::showScore()
{
	system("pause");
	vector<int>v;
	if (Index == 1)
	{
		cout << "第 " << this->Index << "轮晋级结果如下:" << endl;
		v=Round2;
	}
	else
	{
		cout << "本次比赛最终获奖者如下:" << endl;
		v = Victory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号: " << *it << " 姓名: " << this->m_speaker[*it].m_name << " 得分: " << this->m_speaker[*it].m_score[this->Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

void MainManager::saveRecord()  //保存比赛记录
{
	ofstream ofs("record.csv", ios::out | ios::app);
	//将每届比赛的结果写入文件
	for (vector<int>::iterator it = Victory.begin(); it != Victory.end(); it++)
	{
		ofs << *it << "," << this->m_speaker[*it].m_name << "," << this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "比赛记录已自动保存!" << endl;
	this->fileIsEmpty = false;
}

void MainManager::loadRecord()
{
	this->fileIsEmpty = true;
	ifstream ifs("record.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		return;
	}
	fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index = 0;//记录第几届
	while (ifs >> data)
	{
		vector<string>v; //记录往届比赛结果的容器
		int start = 0;
		int pos = -1; //查找到,的位置
		while (1)
		{

			pos = data.find(",",start);
			if (pos == -1)
			{
				v.push_back(data.substr(start)); //将剩余的字符串存入容器
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	return;
}

void MainManager::showHistory()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空或文件不存在!" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < this->m_record.size(); i++)
		{
			cout << "第" << i + 1 << "届比赛结果如下:" << endl;
			cout << "冠军编号: " << this->m_record[i][0] << " 姓名: " << this->m_record[i][1] << " 得分: " << this->m_record[i][2] << endl;
			cout << "亚军编号: " << this->m_record[i][3] << " 姓名: " << this->m_record[i][4] << " 得分: " << this->m_record[i][5] << endl;
			cout << "季军编号: " << this->m_record[i][6] << " 姓名: " << this->m_record[i][7] << " 得分: " << this->m_record[i][8] << endl;
		}
		return;
	}
}

void MainManager::clearRecord()
{
	cout << "  确定要清空所有比赛记录吗? ( 1.确定 / 2.取消 )" << endl;
	int choice;
	while (1)
	{
		cin >> choice;
		if (choice == 1)
		{
			ofstream ofs("record.csv", ios::trunc);
			ofs.close();
			this->initSpeech();
			this->createSpeaker();
			this->loadRecord();
			cout << "所有比赛记录已清空!" << endl;
			return;
		}
		else if (choice == 2)
		{
			cout << "操作已取消!" << endl;
			cout << "正在返回菜单..." << endl;
			return;
		}
		else
		{
			cout << "请选择正确的选项!" << endl;
			continue;
		}
	}
}

MainManager::~MainManager()  //析构函数
{

}