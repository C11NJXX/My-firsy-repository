#pragma once
#include"employee.h"
#include"information.h"

class Staff : public employee
{
public:
	Staff(int num, string name);
	virtual void modifyPosition(int position);//�޸�ְλ
	void showPosition();//չʾְλ�͹�������
};