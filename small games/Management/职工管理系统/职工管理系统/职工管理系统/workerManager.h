#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();

	~WorkerManager();

	//��ӡ�˵�����
	void menu();
	//�˳�ϵͳ����
	void exitSystem();
	//����Ա�����ܣ���������
	void addWorker();
private:
	//��ʼ��ְ������
	int wokerNum;
	//��ʼ��ά��ָ��ְ�����ݶ�����ָ��
	Worker** WokerArray = NULL;
};