#pragma once
#include<string>
using namespace std;
class Worker
{
public:
	//չʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ���� 1->boss 2->manager 3->employee
	virtual string getDeptName() = 0;
protected:
	int workerId;//Ա�����
	string workerName;//Ա������
	int workDepId;//Ա�����ڲ��ű��
};