#include"manager.h"
#include<iostream>
using namespace std;
//���캯��������Ա��������Ϣ
Manager::Manager(int id, string name, int d_id)
{
	this->workerId = id;
	this->workerName = name;
	this->workDepId = d_id;
}

//չʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ����� ��" << this->workerId
		<< "\tְ������ " << this->workerName
		<< "\tְ����λ " << this->getDeptName()
		<< "\t ��������������ܲ��´��ָ��" << endl;
}

//��ȡ��λ���� 2->manager
string Manager::getDeptName()
{
	return (string)"����";
}