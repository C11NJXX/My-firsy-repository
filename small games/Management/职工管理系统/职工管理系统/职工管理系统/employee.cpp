#include"employee.h"
#include<iostream>
using namespace std;
//���캯��������Ա��������Ϣ
Employee::Employee(int id, string name, int d_id)
{
	this->workerId = id;
	this->workerName = name;
	this->workDepId = d_id;
}

//չʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ����� ��" << this->workerId
		<< "\tְ������ " << this->workerName
		<< "\tְ����λ " << this->getDeptName()
		<< "\t ���������ǹ���������˾" << endl;
}

//��ȡ��λ���� 1->Employee
string Employee::getDeptName()
{
	return (string)"��ͨԱ��";
}