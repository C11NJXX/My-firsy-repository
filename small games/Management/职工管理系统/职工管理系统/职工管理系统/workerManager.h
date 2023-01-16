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

	//打印菜单功能
	void menu();
	//退出系统功能
	void exitSystem();
	//增加员工功能（可批量）
	void addWorker();
	//保存文件功能，利用宏已经定义了文件名
	void save();
	//初始化时读取已经存在的职工人数，并返回人数
	int getExistworkerNum();
	//初始化时读取已经存在的职工数据
	void initExistWorker();
	//实现显示员工功能
	void showWorker();
	//实现删除员工功能
	void deleteWorker();
	//利用id判断员工是否存在,由于员工的数据存放在堆区,id号并不能代表该员工在堆区中存储的相对位置,所以利用这个判断函数顺带返回WorkerArray所指堆区元素的下标
	int isWorkerExist(int id);
	//修改员工信息功能
	void modifyWoker();
	//判断用户输入的id是否与已存在的id重复
	int isIdExist(int id);
	//实现查找员工的功能
	void searchWorker();
	//利用姓名判断员工是否存在(重载利用id查询函数)
	int isWorkerExist(string name);
	//利用id对员工进行排序
	void id_sort();
	//清空文件
	void clearWorker();
private:
	//初始化职工人数
	int workerNum;
	//初始化维护指向职工数据堆区的指针
	Worker** WokerArray = NULL;
	//添加bool类型成员变量判断打开程序时文件是否为空或未创建
	bool IsFileEmpty;
	//堆区创建数据统计此次查询的重名人数
	int* p_same_name;
	//临时Worker**指针保存重名数据
	Worker** temp_WorkerArray;
};