#include"manager.h"
#include<iostream>
using namespace std;
//构造函数，传入员工基本信息
Manager::Manager(int id, string name, int d_id)
{
	this->workerId = id;
	this->workerName = name;
	this->workDepId = d_id;
}

//展示个人信息
void Manager::showInfo()
{
	cout << "职工编号 ：" << this->workerId
		<< "\t职工姓名 " << this->workerName
		<< "\t职工岗位 " << this->getDeptName()
		<< "\t 工作内容是完成总裁下达的指令" << endl;
}

//获取岗位名称 2->manager
string Manager::getDeptName()
{
	return (string)"经理";
}