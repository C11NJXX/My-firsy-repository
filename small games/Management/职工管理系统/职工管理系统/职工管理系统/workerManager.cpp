#include"workerManager.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
WorkerManager::WorkerManager()
{

}

WorkerManager::~WorkerManager()
{
	//在析构函数中，释放堆区数据
	if (this->WokerArray != NULL)
	{
		delete[] this->WokerArray;//注意删除是堆区中的数组要加[]
	}
}

//打印菜单功能
void WorkerManager::menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出系统功能
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
//增加员工功能（可批量）
void WorkerManager::addWorker()
{
	//接收用户想要增加员工的人数
	cout << "请输入想要增加的员工个数" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//计算增加新员工后所需要开辟新堆区的大小
		int newSize = this->wokerNum + addNum;
		//开辟新的堆区空间，用newSpace维护,注意堆区中存储的是指向Woker的指针
		Worker** newSpace = new Worker*[newSize];
		//拷贝原有的数据到新的堆区空间(循环原有的数据个数次)
		//判断是否是原先堆区空间是否有数据,如果没有数据则直接跳过
		if (this->WokerArray != NULL)
		{
			for (int i = 0; i < this->wokerNum; i++)
			{
				newSpace[i] = this->WokerArray[i];
			}
		}
		//追加新的所要添加的员工
		for (int i = 0; i < addNum; i++)
		{
			//接收用户对添加员工的初始化
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、boss" << endl;
			cout << "2、manager" << endl;
			cout << "3、employee" << endl;
			cin >> dSelect;
			//创建基类指针
			Worker* worker = NULL;
			//通过选择语句，让基类指针接收对应的派生类员工，并指向其堆区空间
			switch (dSelect)
			{
			case 1: //boss
				worker = new Boss(id, name, 1);
				break;
			case 2: //manager
				worker = new Manager(id, name, 2);
				break;
			case 3:  //employee
				worker = new Employee(id, name, 3);
				break;
			default:
				break;
			}
			//让基类指针 接到 新开辟的堆区空间的尾部
			newSpace[this->wokerNum + i] = worker;
		}
			
			//释放旧的堆区空间，即原有的空间
			delete this->WokerArray;
			//并指向新的堆区空间
			this->WokerArray = newSpace;
			//更新添加后的员工个数
			this->wokerNum = newSize;
			//与用户交互提示添加成功
			cout << "成功添加" << addNum << "名新职工！" << endl;
		
	}
	else
	{
		cout << "请输入合法的数字" << endl;
	}

	system("pause");
	//清屏
	system("cls");
}