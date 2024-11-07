#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "EmpList.txt"
using namespace std;

// Ա�������࣬���ڴ���Ա����ز���
class WorkerManager
{
public:
	int m_EmpNum; // Ա������
	Worker** m_EmpArr; // Ա������
	bool FileIsEmpty; // �ļ��Ƿ�Ϊ��

	WorkerManager(); // ���캯��
	void showMenu(); // ��ʾ�˵�
	void addEmp(); // ���Ա��
	void save(); // ����Ա����Ϣ
	int get_EmpNum(); // ��ȡԱ������
	void init_Emp(); // ��ʼ��Ա����Ϣ
	void Show_Emp(); // ��ʾԱ����Ϣ
	int IsExist(int id); // ���Ա���Ƿ����
	void Del_Emp(); // ɾ��Ա��
	void Mod_Emp(); // �޸�Ա����Ϣ
	void Search_Emp(); // ����Ա��
	void Sort_Emp(); // ����Ա��
	void Clean_File(); // ����ļ�
	void ExitSystem(); // �˳�ϵͳ
	~WorkerManager(); // ��������
};
