#pragma once
#include"employee.h"
#include"information.h"

class Manager : public employee
{
public:
	Manager(int num, string name);
	Manager(const Manager& boss);//�������캯���������ϰ��ɾ���
	virtual void modifyPosition(int position);//�޸�ְλ
	virtual void showPosition();//չʾְλ�͹�������
};