#include"manager.h"

Manager::Manager(int num, string name)
{
	m_number = num;
	m_name = name;
	m_position = 2;//��ʼ��manager���ְλ���Ϊ2
}
Manager::Manager(const Manager& boss)//�������캯���������ϰ��ɾ���,����boss������ʽת��Ϊmanager
{
	
}
void Manager::modifyPosition(int position)
{
	m_position = position;
}

void Manager::showPosition()
{
	cout << m_position << "�ŵ�ְ���� manager ְ���� �����ϰ��ָ�������������¼�" << endl;
}