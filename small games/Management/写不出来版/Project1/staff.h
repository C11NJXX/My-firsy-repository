#pragma once
#include"employee.h"
#include"information.h"

class Staff : public employee
{
public:
	Staff(int num, string name);
	virtual void modifyPosition(int position);//修改职位
	void showPosition();//展示职位和工作内容
};