#pragma once
#include"worker.h"

using namespace std;
class Manager : public Worker
{
public:
	//构造函数，传入员工基本信息
	Manager(int id, string name, int d_id);
	//展示个人信息
	virtual void showInfo();
	//获取岗位名称 1->boss
	virtual string getDeptName();
};