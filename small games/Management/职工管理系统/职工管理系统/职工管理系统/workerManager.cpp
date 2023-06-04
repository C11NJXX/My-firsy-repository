#include"workerManager.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
WorkerManager::WorkerManager()
{

}

WorkerManager::~WorkerManager()
{
	//�����������У��ͷŶ�������
	if (this->WokerArray != NULL)
	{
		delete[] this->WokerArray;//ע��ɾ���Ƕ����е�����Ҫ��[]
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
		int newSize = this->wokerNum + addNum;
		//�����µĶ����ռ䣬��newSpaceά��,ע������д洢����ָ��Woker��ָ��
		Worker** newSpace = new Worker*[newSize];
		//����ԭ�е����ݵ��µĶ����ռ�(ѭ��ԭ�е����ݸ�����)
		//�ж��Ƿ���ԭ�ȶ����ռ��Ƿ�������,���û��������ֱ������
		if (this->WokerArray != NULL)
		{
			for (int i = 0; i < this->wokerNum; i++)
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

			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;

			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1��boss" << endl;
			cout << "2��manager" << endl;
			cout << "3��employee" << endl;
			cin >> dSelect;
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
			newSpace[this->wokerNum + i] = worker;
		}
			
			//�ͷžɵĶ����ռ䣬��ԭ�еĿռ�
			delete this->WokerArray;
			//��ָ���µĶ����ռ�
			this->WokerArray = newSpace;
			//������Ӻ��Ա������
			this->wokerNum = newSize;
			//���û�������ʾ��ӳɹ�
			cout << "�ɹ����" << addNum << "����ְ����" << endl;
		
	}
	else
	{
		cout << "������Ϸ�������" << endl;
	}

	system("pause");
	//����
	system("cls");
}