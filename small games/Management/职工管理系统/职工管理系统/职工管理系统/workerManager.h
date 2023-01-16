#pragma once
#include<iostream>
#include"worker.h"
#define WORKERFILE "workerFile.txt"
#include<fstream>

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
	//�����ļ����ܣ����ú��Ѿ��������ļ���
	void save();
	//��ʼ��ʱ��ȡ�Ѿ����ڵ�ְ������������������
	int getExistworkerNum();
	//��ʼ��ʱ��ȡ�Ѿ����ڵ�ְ������
	void initExistWorker();
	//ʵ����ʾԱ������
	void showWorker();
	//ʵ��ɾ��Ա������
	void deleteWorker();
	//����id�ж�Ա���Ƿ����,����Ա�������ݴ���ڶ���,id�Ų����ܴ����Ա���ڶ����д洢�����λ��,������������жϺ���˳������WorkerArray��ָ����Ԫ�ص��±�
	int isWorkerExist(int id);
	//�޸�Ա����Ϣ����
	void modifyWoker();
	//�ж��û������id�Ƿ����Ѵ��ڵ�id�ظ�
	int isIdExist(int id);
	//ʵ�ֲ���Ա���Ĺ���
	void searchWorker();
	//���������ж�Ա���Ƿ����(��������id��ѯ����)
	int isWorkerExist(string name);
	//����id��Ա����������
	void id_sort();
	//����ļ�
	void clearWorker();
private:
	//��ʼ��ְ������
	int workerNum;
	//��ʼ��ά��ָ��ְ�����ݶ�����ָ��
	Worker** WokerArray = NULL;
	//���bool���ͳ�Ա�����жϴ򿪳���ʱ�ļ��Ƿ�Ϊ�ջ�δ����
	bool IsFileEmpty;
	//������������ͳ�ƴ˴β�ѯ����������
	int* p_same_name;
	//��ʱWorker**ָ�뱣����������
	Worker** temp_WorkerArray;
};