#include"employee.h"
#include<iostream>
using namespace std;
//构造函数，传入员工基本信息
Employee::Employee(int id, string name, int d_id)
{
	this->workerId = id;
	this->workerName = name;
	this->workDepId = d_id;
}

//展示个人信息
void Employee::showInfo()
{
	cout << "职工编号 ：" << this->workerId
		<< "\t职工姓名 " << this->workerName
		<< "\t职工岗位 " << this->getDeptName()
		<< "\t 工作内容是管理整个公司" << endl;
}

//获取岗位名称 1->Employee
string Employee::getDeptName()
{
	return (string)"普通员工";
}