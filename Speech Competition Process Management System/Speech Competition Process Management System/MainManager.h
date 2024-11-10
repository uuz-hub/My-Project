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

	vector<int>Round1; //第一轮比赛
	vector<int>Round2; //第二轮比赛
	vector<int>Victory;  //胜利名单
	map<int, Speaker>m_speaker;  //所有参赛选手
	int Index;  //当前轮数
	map<int,vector<string>>m_record;  //记录文件
	bool fileIsEmpty; //判断文件是否为空
};
