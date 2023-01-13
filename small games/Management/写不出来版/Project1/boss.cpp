#include"boss.h"
#include"manager.h"
Boss::Boss(int num, string name)
{
	m_number = num;
	m_name = name;
	m_position = 1;//初始化boss类的职位编号为1
}

void Boss::modifyPosition(int position)
{
	if (position == m_position)
	{
		cout << "原本的职位就是老板" << endl;
	}
	else if (position == 2)
	{
		cout << "降职变经理" << endl;
		
		Information::m_manager[Information::manageNumber + 1] = new Manager(Information::m_boss[Information::bossNumber]->m_number, Information::m_boss[Information::bossNumber]->m_name);
		
		if (Information::m_boss[Information::bossNumber] != NULL)
		{
			delete Information::m_boss[Information::bossNumber];
			Information::m_boss[Information::bossNumber] = NULL;
			Information::bossNumber -= 1;
		}
	}
	else if (position == 3)
	{
		cout << "老板变员工" << endl;
	}
}

void Boss::showPosition()
{
		cout << m_position << "号的职务是 boss 职责是 管理全公司" << endl;
}