#include"staff.h"

Staff::Staff(int num, string name)
{
	m_number = num;
	m_name = name;
	m_position = 3;//��ʼ��staff���ְλ���Ϊ3
}

void Staff::modifyPosition(int position)
{
	m_position = position;
}

void Staff::showPosition()
{
	cout << m_position << "�ŵ�ְ���� staff ְ���� ����" << endl;
}