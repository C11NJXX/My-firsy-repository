#pragma once
#include"worker.h"

class Employee : public Worker
{
public:
	//���캯��������Ա��������Ϣ
	Employee(int id, string name, int d_id);
	//չʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ���� 1->boss
	virtual string getDeptName();
};