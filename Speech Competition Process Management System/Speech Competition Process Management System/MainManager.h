#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<ctime>
#include<deque>
#include<numeric>
#include<fstream>
#include"Speaker.h"
using namespace std;

class MainManager
{
public:
	MainManager();

	void showMenu();

	void initSpeech();

	void createSpeaker();

	void startSpeech();

	void speechDraw();

	void speechContest();

	void showScore();

	void saveRecord();

	void loadRecord();

	void showHistory();

	void clearRecord();

	void exitSystem();

	~MainManager();

	vector<int>Round1; //��һ�ֱ���
	vector<int>Round2; //�ڶ��ֱ���
	vector<int>Victory;  //ʤ������
	map<int, Speaker>m_speaker;  //���в���ѡ��
	int Index;  //��ǰ����
	map<int,vector<string>>m_record;  //��¼�ļ�
	bool fileIsEmpty; //�ж��ļ��Ƿ�Ϊ��
};
