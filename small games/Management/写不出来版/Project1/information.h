#pragma once

class Boss;
class Manager;
class Staff;

//�����ڶ�������ְԱ��Ϣ
using namespace std;
class Information
{
public:
	Information()
	{
		bossNumber = 0;
		manageNumber = 0;
		staffNumber = 0;
		
	}
	static Boss* m_boss[5];
	static Manager* m_manager[10];
	static Staff* m_staff[50];
	static int bossNumber;
	static int manageNumber;
	static int staffNumber;
};

