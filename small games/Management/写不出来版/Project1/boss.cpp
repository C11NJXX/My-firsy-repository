#include"boss.h"
#include"manager.h"
Boss::Boss(int num, string name)
{
	m_number = num;
	m_name = name;
	m_position = 1;//��ʼ��boss���ְλ���Ϊ1
}

void Boss::modifyPosition(int position)
{
	if (position == m_position)
	{
		cout << "ԭ����ְλ�����ϰ�" << endl;
	}
	else if (position == 2)
	{
		cout << "��ְ�侭��" << endl;
		
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
		cout << "�ϰ��Ա��" << endl;
	}
}

void Boss::showPosition()
{
		cout << m_position << "�ŵ�ְ���� boss ְ���� ����ȫ��˾" << endl;
}