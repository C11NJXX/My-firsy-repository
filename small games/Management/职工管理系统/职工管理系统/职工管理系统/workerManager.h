#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();

	~WorkerManager();

	//打印菜单功能
	void menu();
	//退出系统功能
	void exitSystem();
	//增加员工功能（可批量）
	void addWorker();
private:
	//初始化职工人数
	int wokerNum;
	//初始化维护指向职工数据堆区的指针
	Worker** WokerArray = NULL;
};