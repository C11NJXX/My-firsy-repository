#include"workerManager.h"
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
//����Ա�����Ͷ�̬��ʵ��
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
	//����ѭ�� ֱ���û������˳�
	while (1)
	{
		//��ӡ�˵�
		wm.menu();
		//�����û���ѡ��
		int input = 0;
		cout << "����������ѡ��" << endl;
		cin >> input;
		switch (input)
		{
		case 0: //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: //���ְ��
			wm.addWorker();
			break;
		case 2: //��ʾְ��
			wm.showWorker();
			break;
		case 3: //ɾ��ְ��
			wm.deleteWorker();
			break;
		case 4: //�޸�ְ��
			wm.modifyWoker();
			break;
		case 5: //����ְ��
			wm.searchWorker();
			break;
		case 6: //����ְ��
			wm.id_sort();
			break;
		case 7: //����ļ�
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