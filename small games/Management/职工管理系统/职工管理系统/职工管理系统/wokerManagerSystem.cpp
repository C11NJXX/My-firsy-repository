#include"workerManager.h"
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
//测试员工类型多态的实现
//void test01()
//{
//	Worker* w1 = new Boss(1,"Anne",1);
//	w1->showInfo();
//	delete w1;
//	Worker* w2 = new Manager(2, "Bob", 2);
//	w2->showInfo();
//	delete w2; 
//	Worker* w3 = new Employee(3, "Cate", 3);
//	w3->showInfo();
//	delete w3;
//}

int main()
{
	WorkerManager wm;
	//用死循环 直到用户主动退出
	while (1)
	{
		//打印菜单
		wm.menu();
		//接收用户的选择
		int input = 0;
		cout << "请输入您的选择" << endl;
		cin >> input;
		switch (input)
		{
		case 0: //退出系统
			wm.exitSystem();
			break;
		case 1: //添加职工
			wm.addWorker();
			break;
		case 2: //显示职工
			wm.showWorker();
			break;
		case 3: //删除职工
			wm.deleteWorker();
			break;
		case 4: //修改职工
			wm.modifyWoker();
			break;
		case 5: //查找职工
			wm.searchWorker();
			break;
		case 6: //排序职工
			wm.id_sort();
			break;
		case 7: //清空文件
			wm.clearWorker();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}