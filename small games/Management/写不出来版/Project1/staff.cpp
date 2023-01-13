#include"staff.h"

Staff::Staff(int num, string name)
{
	m_number = num;
	m_name = name;
	m_position = 3;//初始化staff类的职位编号为3
}

void Staff::modifyPosition(int position)
{
	m_position = position;
}

void Staff::showPosition()
{
	cout << m_position << "号的职务是 staff 职责是 打工人" << endl;
}