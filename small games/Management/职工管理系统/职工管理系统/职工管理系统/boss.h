#pragma once
#include"worker.h"

class Boss : public Worker
{
public:
	//���캯��������Ա��������Ϣ
	Boss(int id, string name, int d_id);
	//չʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ���� 1->boss
	virtual string getDeptName();
};