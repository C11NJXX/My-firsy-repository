#pragma once
#include<string>
using namespace std;
class Worker
{
public:
	//展示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称 1->boss 2->manager 3->employee
	virtual string getDeptName() = 0;
protected:
	int workerId;//员工编号
	string workerName;//员工姓名
	int workDepId;//员工所在部门编号
};