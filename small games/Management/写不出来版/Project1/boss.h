#pragma once
#include"employee.h"
#include"information.h"
using namespace std;
class Boss : public employee
{
public:
	Boss(int num, string name);
	virtual void modifyPosition(int position);//�޸�ְλ
	virtual void showPosition();//չʾְλ�͹�������
};

