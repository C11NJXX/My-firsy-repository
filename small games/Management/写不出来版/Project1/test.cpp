#include"information.h"
#include"boss.h"
#include"manager.h"
#include"staff.h"

void test01()
{
	Information::m_boss[Information::bossNumber] = new Boss(1, "Mike");
	Information::m_boss[0]->showPosition();
}
int main()
{
	test01();
	return 0;
}