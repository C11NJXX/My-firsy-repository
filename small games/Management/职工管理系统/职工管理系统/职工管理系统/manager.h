#pragma once
#include"worker.h"

using namespace std;
class Manager : public Worker
{
public:
	//���캯��������Ա��������Ϣ
	Manager(int id, string name, int d_id);
	//չʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ���� 1->boss
	virtual string getDeptName();
};