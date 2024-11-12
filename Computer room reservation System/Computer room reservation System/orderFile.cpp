#include "orderFile.h"

OrderFile::OrderFile()
{
	//从订单文件中读机房、时间、日期、编号、名称和状态信息
	string room;
	string time;
	string date;
	string S_id;
	string S_name;
	string status;

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	this->m_num = 0;
	while (ifs >> room && ifs >> time && ifs >> date && ifs >> S_id && ifs >> S_name && ifs >> status)
	{
		string key;
		string value;
		map<string, string>m;
		int pos = room.find(":");  //查找":"的位置
		if (pos != -1)
		{
			key = room.substr(0, pos);
			value = room.substr(pos + 1, room.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = time.find(":");
		if (pos != -1)
		{
			key = time.substr(0, pos);
			value = time.substr(pos + 1, time.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = S_id.find(":");
		if (pos != -1)
		{
			key = S_id.substr(0, pos);
			value = S_id.substr(pos + 1, S_id.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = S_name.find(":");
		if (pos != -1)
		{
			key = S_name.substr(0, pos);
			value = S_name.substr(pos + 1, S_name.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value)); S_name;
		}
		this->m_orderData.insert(make_pair(this->m_num, m));
		this->m_num++;
	}
	ifs.close();
}

void OrderFile::updateOrder()
{
	if (this->m_num == 0)
	{
		return;
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_num; i++)
	{
		ofs << "room:" << this->m_orderData[i]["room"] << " ";
		ofs << "time:" << this->m_orderData[i]["time"] << " ";
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "S_id:" << this->m_orderData[i]["S_id"] << " ";
		ofs << "S_name:" << this->m_orderData[i]["S_name"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}