#include<iostream>
using namespace std;

void menu()
{
	while (1)
	{
		//打印交互菜单
		cout << "**************职工管理系统***************" << endl;
		cout << " ************0.退出管理程序************" << endl;
		cout << " ************1.增加职工信息************" << endl;
		cout << " ************2.显示职工信息************" << endl;
		cout << " ************3.删除离职职工************" << endl;
		cout << " ************4.修改职工信息************" << endl;
		cout << " ************5.查找职工信息************" << endl;
		cout << " ************6.按照编号排序************" << endl;
		cout << " ************7.清空所有文档************" << endl;
		cout << "*****************************************" << endl;
		//读取用户选择
		int input;
		cout << "请输入所要使用的功能所对应的序号-->";
		do
		{
			cin >> input;
		}while (input < 0 || input>7);
		//用选择语句进入相应函数
		/*switch (input)
		{
		case 0:
			exitSystem();
			break;
		case 1:
			addEmployeeImformation();
			break;
		case 2:
			showEmployeeInformation();
			break;
		case 3:
			deleteEmployeeImformation();
			break;
		case 4:
			modifyEmployeeImformation();
			break;
		case 5:
			searchEmployeeImformation();
			break;
		case 6:
			numberSorting();
			break;
		case 7:
			clearInformation();
		}*/
	}
}