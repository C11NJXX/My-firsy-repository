#include"boss.h"
#include<iostream>
using namespace std;
//���캯��������Ա��������Ϣ
Boss::Boss(int id, string name, int d_id)
{
	this->workerId = id;
	this->workerName = name;
	this->workDepId = d_id;
}

//չʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ����� ��" << this->workerId
		<< "\tְ������ " << this->workerName
		<< "\tְ����λ " << this->getDeptName()
		<< "\t ���������ǹ���������˾" << endl;
}

//��ȡ��λ���� 1->boss
string Boss::getDeptName()
{
	return (string)"�ܲ�";
}