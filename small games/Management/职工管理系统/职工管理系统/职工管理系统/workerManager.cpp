#include"workerManager.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"

//构造函数，判断文件状态，初始化职工个数和读入数据
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(WORKERFILE, ios::in);
	//判断文件是否已经存在
	if (!ifs.is_open())
	{
		cout << "提示:文件打开失败（未创建文件)" << endl;
		//初始化职工人数个数
		this->workerNum = 0;
		//将维护堆区职工数据的指针置空
		this->WokerArray = NULL;
		//保存文件状态 文件为空或不存在
		this->IsFileEmpty = true;
		//关闭文件，并退出构造函数
		ifs.close();
		return;
	}

	//文件存在，但内容为空
	char ch;
	ifs >> ch;
	//让ch接受文件里的第一个字符，如果时文件结尾标志，用 eof（） end of file 函数判断
	if (ifs.eof())
	{
		cout << "提示：文件为空" << endl;
		//初始化职工人数个数
		this->workerNum = 0;
		//将维护堆区职工数据的指针置空
		this->WokerArray = NULL;
		//保存文件状态 文件为空或不存在
		this->IsFileEmpty = true;
		//关闭文件，并退出构造函数
		ifs.close();
		return;
	}
	//文件存在并且内容不为空
	
	//测试
	int num = this->getExistworkerNum();
	//cout << "已存在员工个数:" << num << endl;
	
	//初始化职工人数
	this->workerNum = num;

	//---------以上是判断文件状态并初始化已存在人数-----------//
	//接下来读入已存在职工数据，tips:构造函数中文件还未关闭
	this->WokerArray = new Worker* [this->workerNum];
	initExistWorker();
	//测试
	/*for (int j = 0; j < this->workerNum; j++)
	{
		cout << "职工号： " << this->WokerArray[j]->workerId
			<< " 职工姓名： " << this->WokerArray[j]->workerName
			<< " 部门编号： " << this->WokerArray[j]->workDepId << endl;
	}*/
	ifs.close();
}

WorkerManager::~WorkerManager()
{
	//在析构函数中，释放堆区数据
	if (this->WokerArray != NULL)
	{
		delete[] this->WokerArray;//注意删除是堆区中的数组要加[]
		this->WokerArray = NULL;
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
		int newSize = this->workerNum + addNum;
		//开辟新的堆区空间，用newSpace维护,注意堆区中存储的是指向Woker的指针
		Worker** newSpace = new Worker*[newSize];
		//拷贝原有的数据到新的堆区空间(循环原有的数据个数次)
		//判断是否是原先堆区空间是否有数据,如果没有数据则直接跳过
		if (this->WokerArray != NULL)
		{
			for (int i = 0; i < this->workerNum; i++)
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
			re_input_id:cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;
			//判断用户是否输入重id
			int is_re_id = this->isIdExist(id);
			if (is_re_id == -1)
			{
				cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
				cin >> name;

				cout << "请选择该职工的岗位：" << endl;
				cout << "1、boss" << endl;
				cout << "2、manager" << endl;
				cout << "3、employee" << endl;
				cin >> dSelect;
			}
			else
			{
				cout << "该ID已存在！" << endl;
				goto re_input_id;
			}
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
			newSpace[this->workerNum + i] = worker;
		}
			
			//释放旧的堆区空间，即原有的空间
			delete this->WokerArray;
			//并指向新的堆区空间
			this->WokerArray = newSpace;
			//更新添加后的员工个数
			this->workerNum = newSize;
			//与用户交互提示添加成功
			cout << "成功添加" << addNum << "名新职工！" << endl;
			//保存文件
			save();
			//将判断文件是否为空的变量置为否
			this->IsFileEmpty = false;
		
	}
	else
	{
		cout << "请输入合法的数字" << endl;
	}

	system("pause");
	//清屏
	system("cls");
}

//保存文件功能，利用宏已经定义了文件名
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(WORKERFILE, ios::out);
	for (int i = 0; i < this->workerNum; i++)
	{
		ofs << this->WokerArray[i]->workerId << " "
			<< this->WokerArray[i]->workerName << " "
			<< this->WokerArray[i]->workDepId << endl;
	}
	ofs.close();
}

//初始化时读取已经存在的职工人数，并返回人数
int WorkerManager::getExistworkerNum()
{
	ifstream ifs;
	ifs.open(WORKERFILE, ios::in);
	//创建局部员工数据类型
	int id;
	string name;
	int dId;
	//创建局部变量统计已有人数，结合文件保存格式，一行一行读取并统计人数
	int existNum = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		existNum += 1;
	}
	ifs.close();
	//返回已有人数，在构造函数中第三种情况中使用
	return existNum;
}

//初始化时读取已经存在的职工数据
void WorkerManager::initExistWorker()
{
	ifstream ifs;
	ifs.open(WORKERFILE, ios::in);
	int id;
	string name;
	int dId;
	//数组下标
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		switch (dId)
		{
		case 1:
			worker = new Boss(id, name, dId);
			break;
		case 2:
			worker = new Manager(id, name, dId);
			break;
		case 3:
			worker = new Employee(id, name, dId);
			break;
		}
		this->WokerArray[index] = worker;
		index++;
	}
	ifs.close();
}

//实现显示员工功能
void WorkerManager::showWorker()
{
	//先根据bool变量判断文件的状态
	if (this->IsFileEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->workerNum; i++)
		{
			this->WokerArray[i]->showInfo();
		}
	}
	system("pause");
	//system("cls"); 不清屏方便用户使用
}

//实现删除员工功能
void WorkerManager::deleteWorker()
{
	//首先要判断文件状态
	if (this->IsFileEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		//接受用户输入所要删除员工的id号
		cout << "请输入想要删除的员工的id号" << endl;
		int id;
		cin >> id;
		//判断是否有对应员工，即判断此id号的员工是否存在,用index接收，顺便做下标
		int index = isWorkerExist(id);
		if (index == -1)
		{
			cout << "此id没有对应的员工存在" << endl;
		}
		else//删除index下标的员工
		{
			//利用覆盖技术
			for (int i = index; i < this->workerNum - 1; i++)
			{
				this->WokerArray[i] = this->WokerArray[i + 1];
			}
			this->workerNum--;//总员工个数减一
			//保存修改后的文件
			save();
			//提示删除成功
			cout << "已删除id号为 " << id << "号的员工!" << endl;
		}
	}
	system("pause");
	system("cls");
}

//利用id判断员工是否存在
int WorkerManager::isWorkerExist(int id)
{
	//遍历已存在的员工数据，查看是否有对应员工
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->WokerArray[i]->workerId == id)
		{
			//返回WorkerArray所指堆区元素的下标
			return i;
		}
	}
	//不存在返回-1
	return -1;
}

//修改员工信息功能
void WorkerManager::modifyWoker()
{
	//判断文件状态
	if (this->IsFileEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		cout << "请输入所要修改的员工编号" << endl;
		int id;
		cin >> id;
		int index;//用index来接收函数返回值并做下标
		index = this->isWorkerExist(id);
		if (index == -1)
		{
			cout << "此id没有对应的员工存在" << endl;
		}
		else//员工存在
		{
			//修改员工数据，直接接收用户重新输入的数据，覆盖到该员工上
			 
			//判断用户输入的id是否与已经存在的id重复
			cout << "请输入修改后的员工id" << endl;
			int re_id;
			cin >> re_id;
			int index_ = this->isIdExist(re_id);
			if (index_ != -1 && re_id!= this->WokerArray[index]->workerId)
			{
				cout << "查询到重id！此id所对应的员工信息为" << endl;
				this->WokerArray[this->isWorkerExist(re_id)]->showInfo();
				cout << "修改失败" << endl;
			}
			else//修改员工数据
			{
				cout << "id修改成功!" << endl;
				this->WokerArray[index]->workerId = re_id;//这里有意思的是用原本数据所在堆区的内容被覆盖
				cout << "请输入修改后的员工姓名" << endl;
				string re_name;
				cin >> re_name;
				this->WokerArray[index]->workerName = re_name;
				cout << "姓名修改成功！" << endl;
				cout << "请输入修改后的员工职位\n 1.boss 2.manager 3.employee" << endl;
				int re_dId;
				cin >> re_dId;
				this->WokerArray[index]->workDepId = re_dId;
				cout << "职位修改成功!" << endl;
				//保存修改后的数据
				save();
				//提示全部修改成功
				cout << "员工信息修改成功！" << endl;
				//保存修改后的数据
				save();
			}
		}
	}
	system("pause");
	system("cls");
}

//判断用户输入的id是否与已存在的id重复,同理返回index,但是会出bug，如果修改的编号不是原本的编号就会出错
//长个记性就保留这个返回类型了
int WorkerManager::isIdExist(int id)
{
	//利用遍历已存在员工的数据查看是否重id
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->WokerArray[i]->workerId == id)
		{
			return i;
		}
	}
	return -1;//没有重复id
}

//利用姓名判断员工是否存在,并且可以记录重名人数(重载利用id查询函数)
int WorkerManager::isWorkerExist(string name)
{
	//重名人数统计
	//初始化重名人数
	p_same_name = new int;
	*(p_same_name) = 0;
	//初始化临时指针
	temp_WorkerArray = new Worker * [10];//后期同名人数过多，可以修改创建的值
	//临时下标
	int index = 0;
	
	//遍历已存在员工数据,记录有几个同名
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->WokerArray[i]->workerName == name)
		{
			temp_WorkerArray[index] = this->WokerArray[i];//临时数据保存
			index++;//下标更新
			(*p_same_name)++;//同名人数更新
		}
	}
	if (*(p_same_name) == 0)
	{
		return -1;//没有查询到对应员工
	}
	else if (*(p_same_name) == 1)
	{
		return 1;//查询到一个对应员工
	}
	else
	{
		return 2;//查询到多个匹配
	}
}

//实现查找员工的功能
void WorkerManager::searchWorker()
{
	//判断文件状态
	if (this->IsFileEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		//选择用id或者姓名查询
		cout << "请选择：1、id查询 2、姓名查询（重名全部输出）" << endl;
		int input;
		reput: cin >> input;
		switch (input)
		{
		case 1://接收用户输入的所要查询的员工的id并判断是否存在
		{
			cout << "请输入id" << endl;
			int id;
			cin >> id;
			int index = this->isWorkerExist(id);
			if (index == -1)
			{
				cout << "员工不存在" << endl;
			}
			else//提示查询成功，并显示信息
			{
				cout << "查询到匹配数据！" << endl;
				this->WokerArray[index]->showInfo();
			}
			break;
		}
		case 2://接收用户输入所要查询的员工的姓名并判断是否存在，考虑重名
		{
			cout << "请输入所要查询的员工姓名" << endl;
			string name;
			cin >> name;
			//用临时变量接收返回值进行分类处理
			int ret = this->isWorkerExist(name);
			switch (ret)
			{
			case 0:
				cout << "没有查询到对应的员工" << endl;
				break;
			case 1:
				cout << "查询到一个匹配结果" << endl;
				temp_WorkerArray[0]->showInfo();
				break;
			case 2:
				cout << "查询到" << *(p_same_name) << "个名为" << name << "的员工" << endl;
				for (int i = 0; i < *(p_same_name); i++)
				{
					temp_WorkerArray[i]->showInfo();
				}
				break;
			}
			delete p_same_name;
			delete[] temp_WorkerArray;
			break;
		}
		default:
			goto reput;
		}
		
	}
	system("pause");
	system("cls");
}

//利用id对员工进行排序
void WorkerManager::id_sort()
{
	//让用户选择是升序还是降序
	re_input:cout << "请选择1.升序 2.降序" << endl;
	int input;
	cin >> input;
	switch (input)
	{
	case 1:
		for (int i = 0; i < this->workerNum-1; i++)
		{
			for (int j = 0; j < this->workerNum - 1 - i; j++)
			{
				if (this->WokerArray[j]->workerId > this->WokerArray[j + 1]->workerId)
				{
					Worker* tmp = this->WokerArray[j];
					this->WokerArray[j] = this->WokerArray[j + 1];
					this->WokerArray[j + 1] = tmp;
				}
			}
		}
		cout << "已按照升序排列" << endl;
		this->save();
		break;
	case 2:
		for (int i = 0; i < this->workerNum - 1; i++)
		{
			for (int j = 0; j < this->workerNum - 1 - i; j++)
			{
				if (this->WokerArray[j]->workerId < this->WokerArray[j + 1]->workerId)
				{
					Worker* tmp = this->WokerArray[j];
					this->WokerArray[j] = this->WokerArray[j + 1];
					this->WokerArray[j + 1] = tmp;
				}
			}
		}
		cout << "已按照降序排列" << endl;
		this->save();
		break;
	default:
		cout << "请重新输入" << endl;
		goto re_input;
		break;
	}
	system("pause");
	system("cls");
}

//清空文件
void WorkerManager::clearWorker()
{
	//提示用户确认清除？防止误点
	re_input:cout << "请确定 1、确认清楚2、不清除\n！后果自负！" << endl;
	int input;
	cin >> input;
	switch (input)
	{
	case 1:
	{
		//打开文件，如果文件存在则删除文件重新创建
		ofstream ofs;
		ofs.open(WORKERFILE, ios::trunc);
		//判断文件是否打开成功
		if (IsFileEmpty)
		{
			cout << "文件不存在或为空 " << endl;
			system("pause");
			system("cls");
			return;
		}
		else//清空堆区的员工数据，再删除维护数据的堆区指针，更新数据，人数为零，文件为空
		{
			if (this->WokerArray != NULL)
			{
				for (int i = 0; i < this->workerNum; i++)
				{
					if (this->WokerArray[i] != NULL)
					{
						delete this->WokerArray[i];
					}
				}
			}
			delete[] this->WokerArray;
			this->WokerArray = NULL;
			this->workerNum = 0;
			IsFileEmpty = true;
			cout << "已成功删除数据！" << endl;
		}
		break;
	}
	case 2:
		cout << "退回主菜单！" << endl;
		break;
	default:
		cout << "请重新输入" << endl;
		goto re_input;
		break;
	}
	system("pause");
	system("cls");
}