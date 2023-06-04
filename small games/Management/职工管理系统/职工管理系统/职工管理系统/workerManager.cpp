#include"workerManager.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"

//���캯�����ж��ļ�״̬����ʼ��ְ�������Ͷ�������
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(WORKERFILE, ios::in);
	//�ж��ļ��Ƿ��Ѿ�����
	if (!ifs.is_open())
	{
		cout << "��ʾ:�ļ���ʧ�ܣ�δ�����ļ�)" << endl;
		//��ʼ��ְ����������
		this->workerNum = 0;
		//��ά������ְ�����ݵ�ָ���ÿ�
		this->WokerArray = NULL;
		//�����ļ�״̬ �ļ�Ϊ�ջ򲻴���
		this->IsFileEmpty = true;
		//�ر��ļ������˳����캯��
		ifs.close();
		return;
	}

	//�ļ����ڣ�������Ϊ��
	char ch;
	ifs >> ch;
	//��ch�����ļ���ĵ�һ���ַ������ʱ�ļ���β��־���� eof���� end of file �����ж�
	if (ifs.eof())
	{
		cout << "��ʾ���ļ�Ϊ��" << endl;
		//��ʼ��ְ����������
		this->workerNum = 0;
		//��ά������ְ�����ݵ�ָ���ÿ�
		this->WokerArray = NULL;
		//�����ļ�״̬ �ļ�Ϊ�ջ򲻴���
		this->IsFileEmpty = true;
		//�ر��ļ������˳����캯��
		ifs.close();
		return;
	}
	//�ļ����ڲ������ݲ�Ϊ��
	
	//����
	int num = this->getExistworkerNum();
	//cout << "�Ѵ���Ա������:" << num << endl;
	
	//��ʼ��ְ������
	this->workerNum = num;

	//---------�������ж��ļ�״̬����ʼ���Ѵ�������-----------//
	//�����������Ѵ���ְ�����ݣ�tips:���캯�����ļ���δ�ر�
	this->WokerArray = new Worker* [this->workerNum];
	initExistWorker();
	//����
	/*for (int j = 0; j < this->workerNum; j++)
	{
		cout << "ְ���ţ� " << this->WokerArray[j]->workerId
			<< " ְ�������� " << this->WokerArray[j]->workerName
			<< " ���ű�ţ� " << this->WokerArray[j]->workDepId << endl;
	}*/
	ifs.close();
}

WorkerManager::~WorkerManager()
{
	//�����������У��ͷŶ�������
	if (this->WokerArray != NULL)
	{
		delete[] this->WokerArray;//ע��ɾ���Ƕ����е�����Ҫ��[]
		this->WokerArray = NULL;
	}
}

//��ӡ�˵�����
void WorkerManager::menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ����
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//����Ա�����ܣ���������
void WorkerManager::addWorker()
{
	//�����û���Ҫ����Ա��������
	cout << "��������Ҫ���ӵ�Ա������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//����������Ա��������Ҫ�����¶����Ĵ�С
		int newSize = this->workerNum + addNum;
		//�����µĶ����ռ䣬��newSpaceά��,ע������д洢����ָ��Woker��ָ��
		Worker** newSpace = new Worker*[newSize];
		//����ԭ�е����ݵ��µĶ����ռ�(ѭ��ԭ�е����ݸ�����)
		//�ж��Ƿ���ԭ�ȶ����ռ��Ƿ�������,���û��������ֱ������
		if (this->WokerArray != NULL)
		{
			for (int i = 0; i < this->workerNum; i++)
			{
				newSpace[i] = this->WokerArray[i];
			}
		}
		//׷���µ���Ҫ��ӵ�Ա��
		for (int i = 0; i < addNum; i++)
		{
			//�����û������Ա���ĳ�ʼ��
			int id;
			string name;
			int dSelect;
			re_input_id:cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;
			//�ж��û��Ƿ�������id
			int is_re_id = this->isIdExist(id);
			if (is_re_id == -1)
			{
				cout << "������� " << i + 1 << " ����ְ��������" << endl;
				cin >> name;

				cout << "��ѡ���ְ���ĸ�λ��" << endl;
				cout << "1��boss" << endl;
				cout << "2��manager" << endl;
				cout << "3��employee" << endl;
				cin >> dSelect;
			}
			else
			{
				cout << "��ID�Ѵ��ڣ�" << endl;
				goto re_input_id;
			}
			//��������ָ��
			Worker* worker = NULL;
			//ͨ��ѡ����䣬�û���ָ����ն�Ӧ��������Ա������ָ��������ռ�
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
			//�û���ָ�� �ӵ� �¿��ٵĶ����ռ��β��
			newSpace[this->workerNum + i] = worker;
		}
			
			//�ͷžɵĶ����ռ䣬��ԭ�еĿռ�
			delete this->WokerArray;
			//��ָ���µĶ����ռ�
			this->WokerArray = newSpace;
			//������Ӻ��Ա������
			this->workerNum = newSize;
			//���û�������ʾ��ӳɹ�
			cout << "�ɹ����" << addNum << "����ְ����" << endl;
			//�����ļ�
			save();
			//���ж��ļ��Ƿ�Ϊ�յı�����Ϊ��
			this->IsFileEmpty = false;
		
	}
	else
	{
		cout << "������Ϸ�������" << endl;
	}

	system("pause");
	//����
	system("cls");
}

//�����ļ����ܣ����ú��Ѿ��������ļ���
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

//��ʼ��ʱ��ȡ�Ѿ����ڵ�ְ������������������
int WorkerManager::getExistworkerNum()
{
	ifstream ifs;
	ifs.open(WORKERFILE, ios::in);
	//�����ֲ�Ա����������
	int id;
	string name;
	int dId;
	//�����ֲ�����ͳ����������������ļ������ʽ��һ��һ�ж�ȡ��ͳ������
	int existNum = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		existNum += 1;
	}
	ifs.close();
	//���������������ڹ��캯���е����������ʹ��
	return existNum;
}

//��ʼ��ʱ��ȡ�Ѿ����ڵ�ְ������
void WorkerManager::initExistWorker()
{
	ifstream ifs;
	ifs.open(WORKERFILE, ios::in);
	int id;
	string name;
	int dId;
	//�����±�
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

//ʵ����ʾԱ������
void WorkerManager::showWorker()
{
	//�ȸ���bool�����ж��ļ���״̬
	if (this->IsFileEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->workerNum; i++)
		{
			this->WokerArray[i]->showInfo();
		}
	}
	system("pause");
	//system("cls"); �����������û�ʹ��
}

//ʵ��ɾ��Ա������
void WorkerManager::deleteWorker()
{
	//����Ҫ�ж��ļ�״̬
	if (this->IsFileEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		//�����û�������Ҫɾ��Ա����id��
		cout << "��������Ҫɾ����Ա����id��" << endl;
		int id;
		cin >> id;
		//�ж��Ƿ��ж�ӦԱ�������жϴ�id�ŵ�Ա���Ƿ����,��index���գ�˳�����±�
		int index = isWorkerExist(id);
		if (index == -1)
		{
			cout << "��idû�ж�Ӧ��Ա������" << endl;
		}
		else//ɾ��index�±��Ա��
		{
			//���ø��Ǽ���
			for (int i = index; i < this->workerNum - 1; i++)
			{
				this->WokerArray[i] = this->WokerArray[i + 1];
			}
			this->workerNum--;//��Ա��������һ
			//�����޸ĺ���ļ�
			save();
			//��ʾɾ���ɹ�
			cout << "��ɾ��id��Ϊ " << id << "�ŵ�Ա��!" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����id�ж�Ա���Ƿ����
int WorkerManager::isWorkerExist(int id)
{
	//�����Ѵ��ڵ�Ա�����ݣ��鿴�Ƿ��ж�ӦԱ��
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->WokerArray[i]->workerId == id)
		{
			//����WorkerArray��ָ����Ԫ�ص��±�
			return i;
		}
	}
	//�����ڷ���-1
	return -1;
}

//�޸�Ա����Ϣ����
void WorkerManager::modifyWoker()
{
	//�ж��ļ�״̬
	if (this->IsFileEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�Ա�����" << endl;
		int id;
		cin >> id;
		int index;//��index�����պ�������ֵ�����±�
		index = this->isWorkerExist(id);
		if (index == -1)
		{
			cout << "��idû�ж�Ӧ��Ա������" << endl;
		}
		else//Ա������
		{
			//�޸�Ա�����ݣ�ֱ�ӽ����û�������������ݣ����ǵ���Ա����
			 
			//�ж��û������id�Ƿ����Ѿ����ڵ�id�ظ�
			cout << "�������޸ĺ��Ա��id" << endl;
			int re_id;
			cin >> re_id;
			int index_ = this->isIdExist(re_id);
			if (index_ != -1 && re_id!= this->WokerArray[index]->workerId)
			{
				cout << "��ѯ����id����id����Ӧ��Ա����ϢΪ" << endl;
				this->WokerArray[this->isWorkerExist(re_id)]->showInfo();
				cout << "�޸�ʧ��" << endl;
			}
			else//�޸�Ա������
			{
				cout << "id�޸ĳɹ�!" << endl;
				this->WokerArray[index]->workerId = re_id;//��������˼������ԭ���������ڶ��������ݱ�����
				cout << "�������޸ĺ��Ա������" << endl;
				string re_name;
				cin >> re_name;
				this->WokerArray[index]->workerName = re_name;
				cout << "�����޸ĳɹ���" << endl;
				cout << "�������޸ĺ��Ա��ְλ\n 1.boss 2.manager 3.employee" << endl;
				int re_dId;
				cin >> re_dId;
				this->WokerArray[index]->workDepId = re_dId;
				cout << "ְλ�޸ĳɹ�!" << endl;
				//�����޸ĺ������
				save();
				//��ʾȫ���޸ĳɹ�
				cout << "Ա����Ϣ�޸ĳɹ���" << endl;
				//�����޸ĺ������
				save();
			}
		}
	}
	system("pause");
	system("cls");
}

//�ж��û������id�Ƿ����Ѵ��ڵ�id�ظ�,ͬ����index,���ǻ��bug������޸ĵı�Ų���ԭ���ı�žͻ����
//�������Ծͱ����������������
int WorkerManager::isIdExist(int id)
{
	//���ñ����Ѵ���Ա�������ݲ鿴�Ƿ���id
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->WokerArray[i]->workerId == id)
		{
			return i;
		}
	}
	return -1;//û���ظ�id
}

//���������ж�Ա���Ƿ����,���ҿ��Լ�¼��������(��������id��ѯ����)
int WorkerManager::isWorkerExist(string name)
{
	//��������ͳ��
	//��ʼ����������
	p_same_name = new int;
	*(p_same_name) = 0;
	//��ʼ����ʱָ��
	temp_WorkerArray = new Worker * [10];//����ͬ���������࣬�����޸Ĵ�����ֵ
	//��ʱ�±�
	int index = 0;
	
	//�����Ѵ���Ա������,��¼�м���ͬ��
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->WokerArray[i]->workerName == name)
		{
			temp_WorkerArray[index] = this->WokerArray[i];//��ʱ���ݱ���
			index++;//�±����
			(*p_same_name)++;//ͬ����������
		}
	}
	if (*(p_same_name) == 0)
	{
		return -1;//û�в�ѯ����ӦԱ��
	}
	else if (*(p_same_name) == 1)
	{
		return 1;//��ѯ��һ����ӦԱ��
	}
	else
	{
		return 2;//��ѯ�����ƥ��
	}
}

//ʵ�ֲ���Ա���Ĺ���
void WorkerManager::searchWorker()
{
	//�ж��ļ�״̬
	if (this->IsFileEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		//ѡ����id����������ѯ
		cout << "��ѡ��1��id��ѯ 2��������ѯ������ȫ�������" << endl;
		int input;
		reput: cin >> input;
		switch (input)
		{
		case 1://�����û��������Ҫ��ѯ��Ա����id���ж��Ƿ����
		{
			cout << "������id" << endl;
			int id;
			cin >> id;
			int index = this->isWorkerExist(id);
			if (index == -1)
			{
				cout << "Ա��������" << endl;
			}
			else//��ʾ��ѯ�ɹ�������ʾ��Ϣ
			{
				cout << "��ѯ��ƥ�����ݣ�" << endl;
				this->WokerArray[index]->showInfo();
			}
			break;
		}
		case 2://�����û�������Ҫ��ѯ��Ա�����������ж��Ƿ���ڣ���������
		{
			cout << "��������Ҫ��ѯ��Ա������" << endl;
			string name;
			cin >> name;
			//����ʱ�������շ���ֵ���з��ദ��
			int ret = this->isWorkerExist(name);
			switch (ret)
			{
			case 0:
				cout << "û�в�ѯ����Ӧ��Ա��" << endl;
				break;
			case 1:
				cout << "��ѯ��һ��ƥ����" << endl;
				temp_WorkerArray[0]->showInfo();
				break;
			case 2:
				cout << "��ѯ��" << *(p_same_name) << "����Ϊ" << name << "��Ա��" << endl;
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

//����id��Ա����������
void WorkerManager::id_sort()
{
	//���û�ѡ���������ǽ���
	re_input:cout << "��ѡ��1.���� 2.����" << endl;
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
		cout << "�Ѱ�����������" << endl;
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
		cout << "�Ѱ��ս�������" << endl;
		this->save();
		break;
	default:
		cout << "����������" << endl;
		goto re_input;
		break;
	}
	system("pause");
	system("cls");
}

//����ļ�
void WorkerManager::clearWorker()
{
	//��ʾ�û�ȷ���������ֹ���
	re_input:cout << "��ȷ�� 1��ȷ�����2�������\n������Ը���" << endl;
	int input;
	cin >> input;
	switch (input)
	{
	case 1:
	{
		//���ļ�������ļ�������ɾ���ļ����´���
		ofstream ofs;
		ofs.open(WORKERFILE, ios::trunc);
		//�ж��ļ��Ƿ�򿪳ɹ�
		if (IsFileEmpty)
		{
			cout << "�ļ������ڻ�Ϊ�� " << endl;
			system("pause");
			system("cls");
			return;
		}
		else//��ն�����Ա�����ݣ���ɾ��ά�����ݵĶ���ָ�룬�������ݣ�����Ϊ�㣬�ļ�Ϊ��
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
			cout << "�ѳɹ�ɾ�����ݣ�" << endl;
		}
		break;
	}
	case 2:
		cout << "�˻����˵���" << endl;
		break;
	default:
		cout << "����������" << endl;
		goto re_input;
		break;
	}
	system("pause");
	system("cls");
}