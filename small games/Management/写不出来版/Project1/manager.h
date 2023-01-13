#pragma once
#include"employee.h"
#include"information.h"

class Manager : public employee
{
public:
	Manager(int num, string name);
	Manager(const Manager& boss);//拷贝构造函数用来将老板变成经理
	virtual void modifyPosition(int position);//修改职位
	virtual void showPosition();//展示职位和工作内容
};