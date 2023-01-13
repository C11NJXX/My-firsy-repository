#pragma once
#include<iostream>
#include<string>

using namespace std;

class employee
{
public :
	void modifyName(string name);//修改姓名
	virtual void modifyPosition(int position) = 0;//修改职位
	virtual void showPosition() {};//展示职位和工作内容
protected:
	int m_number{};
	string m_name;
	int m_position{};
};


//在改变职位后，希望的是新创建一个对应职位的实例对象
//也就是需要写拷贝构造函数，用原有的不同类的对象
//制作出一个新的职位类型的对象，需要拷贝编号，姓名
//同时再把原职位的对象删除
//因此三种类的对象的创建需要用指针来维护