#pragma once
#include"employee.h"
#include"information.h"
using namespace std;
class Boss : public employee
{
public:
	Boss(int num, string name);
	virtual void modifyPosition(int position);//修改职位
	virtual void showPosition();//展示职位和工作内容
};

