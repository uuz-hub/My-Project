#include "MainManager.h"  //����ϵͳ�����ļ�
class myeach
{
public:
	bool operator()(int i)
	{
		cout << i << "  ";
		return true;	
	}
};

MainManager::MainManager()  //���캯��
{
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}

void MainManager::showMenu()  //��ʾ�˵�
{
	 cout << " ----------------------" << endl;
	 cout << "|   ��ӭ�μ��ݽ�����!  |" << endl;
	 cout << "|    1.��ʼ�ݽ�����    |" << endl;
	 cout << "|    2.�鿴�����¼    |" << endl;
	 cout << "|    3.��ձ�����¼    |" << endl;
	 cout << "|    0.�˳���������    |" << endl;
	 cout << " ----------------------" << endl;
}  

void MainManager::exitSystem()  //�˳�ϵͳ
{
	cout << "��ӭ�´�ʹ��!" << endl;
	system("pause");
	exit(0);
}  

void MainManager::initSpeech()  //��ʼ��ϵͳ
{
	this->Index = 1;
	this->Round1.clear();
	this->Round2.clear();
	this->Victory.clear();
	this->m_speaker.clear();
	this->m_record.clear(); 
}

void MainManager::createSpeaker()  //�����ݽ���
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		Speaker sp;
		string name = "ѡ��";
		name += nameSeed[i];
		sp.m_name = name;

		this->Round1.push_back(i + 10001);
		this->m_speaker.insert(make_pair(i + 10001, sp));
	}
}

void MainManager::startSpeech()
{
	//��һ�ֱ���

	//��ǩ
	speechDraw();
	//����
	speechContest();
	//��ʾ�������
	showScore();
    //�ڶ��ֱ���
	this->Index++;
	//��ǩ
	speechDraw();
	//����
	speechContest();
	//��¼���ս��
	showScore();
	//���������¼
	saveRecord();
	cout << "����������!" << endl;
	//���ñ���
	//��ʼ������������
	initSpeech();
	//���´����ݽ���
	createSpeaker();
	//���¼��ؼ�¼
	loadRecord();
}

void MainManager::speechDraw() //��ǩ
{
	if (Index == 1)  //��һ�ֱ���
	{
		cout << "��  " << this->Index << "  �ֱ������ڳ�ǩ" << endl;
		system("pause");
		cout << "----------------------------------" << endl;
		cout << "��ǩ���ݽ�˳������:" << endl;
		random_shuffle(Round1.begin(), Round1.end());
		for_each(Round1.begin(), Round1.end(), myeach());
		cout << endl;
	}
	else  //�ڶ��ֱ���
	{
		cout << "��  " << this->Index << "  �ֱ������ڳ�ǩ" << endl;
		system("pause");
		cout << "--------------------------------------------" << endl;
		cout << "��ǩ���ݽ�˳������:" << endl;
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
	multimap<double, int, greater<double> >groupScore; //��¼ÿ����ĵ÷�
	cout << "��  " << this->Index << "  �ֱ������ڽ���" << endl;
	system("pause");
	int num = 0; //��¼��Ա�� , 6��Ϊһ��
	vector<int>v_Src; //������Ա����
	if (Index == 1)  //��һ�ֱ���
	{
		v_Src = Round1;
	}
	else  //�ڶ��ֱ���
	{
		v_Src = Round2;
	}
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		deque<double>d;  //��¼ÿ���ݽ��ߵĵ÷�
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; //�������60-100֮��ķ���
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		//ƽ���ַ���map����
		this->m_speaker[*it].m_score[this->Index -1] = avg;
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "�� " << num / 6 << " ��С������������:" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "���: " << it->second << "  ����: " << this->m_speaker[it->second].m_name << "  �÷�: " << this->m_speaker[it->second].m_score[this->Index - 1] << endl;
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
	cout << "��" << this->Index << "�ֱ�������" << endl;
}

void MainManager::showScore()
{
	system("pause");
	vector<int>v;
	if (Index == 1)
	{
		cout << "�� " << this->Index << "�ֽ����������:" << endl;
		v=Round2;
	}
	else
	{
		cout << "���α������ջ�������:" << endl;
		v = Victory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "���: " << *it << " ����: " << this->m_speaker[*it].m_name << " �÷�: " << this->m_speaker[*it].m_score[this->Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

void MainManager::saveRecord()  //���������¼
{
	ofstream ofs("record.csv", ios::out | ios::app);
	//��ÿ������Ľ��д���ļ�
	for (vector<int>::iterator it = Victory.begin(); it != Victory.end(); it++)
	{
		ofs << *it << "," << this->m_speaker[*it].m_name << "," << this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "������¼���Զ�����!" << endl;
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
	int index = 0;//��¼�ڼ���
	while (ifs >> data)
	{
		vector<string>v; //��¼����������������
		int start = 0;
		int pos = -1; //���ҵ�,��λ��
		while (1)
		{

			pos = data.find(",",start);
			if (pos == -1)
			{
				v.push_back(data.substr(start)); //��ʣ����ַ�����������
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
		cout << "�ļ�Ϊ�ջ��ļ�������!" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < this->m_record.size(); i++)
		{
			cout << "��" << i + 1 << "������������:" << endl;
			cout << "�ھ����: " << this->m_record[i][0] << " ����: " << this->m_record[i][1] << " �÷�: " << this->m_record[i][2] << endl;
			cout << "�Ǿ����: " << this->m_record[i][3] << " ����: " << this->m_record[i][4] << " �÷�: " << this->m_record[i][5] << endl;
			cout << "�������: " << this->m_record[i][6] << " ����: " << this->m_record[i][7] << " �÷�: " << this->m_record[i][8] << endl;
		}
		return;
	}
}

void MainManager::clearRecord()
{
	cout << "  ȷ��Ҫ������б�����¼��? ( 1.ȷ�� / 2.ȡ�� )" << endl;
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
			cout << "���б�����¼�����!" << endl;
			return;
		}
		else if (choice == 2)
		{
			cout << "������ȡ��!" << endl;
			cout << "���ڷ��ز˵�..." << endl;
			return;
		}
		else
		{
			cout << "��ѡ����ȷ��ѡ��!" << endl;
			continue;
		}
	}
}

MainManager::~MainManager()  //��������
{

}