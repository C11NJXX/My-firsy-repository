#include"manager.h"

Manager::Manager(int num, string name)
{
	m_number = num;
	m_name = name;
	m_position = 2;//初始化manager类的职位编号为2
}
Manager::Manager(const Manager& boss)//拷贝构造函数用来将老板变成经理,传入boss对象隐式转换为manager
{
	
}
void Manager::modifyPosition(int position)
{
	m_position = position;
}

void Manager::showPosition()
{
	cout << m_position << "号的职务是 manager 职责是 接受老板的指令并分配任务个给下级" << endl;
}