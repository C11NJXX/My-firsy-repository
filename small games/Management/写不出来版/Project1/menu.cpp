#include<iostream>
using namespace std;

void menu()
{
	while (1)
	{
		//��ӡ�����˵�
		cout << "**************ְ������ϵͳ***************" << endl;
		cout << " ************0.�˳��������************" << endl;
		cout << " ************1.����ְ����Ϣ************" << endl;
		cout << " ************2.��ʾְ����Ϣ************" << endl;
		cout << " ************3.ɾ����ְְ��************" << endl;
		cout << " ************4.�޸�ְ����Ϣ************" << endl;
		cout << " ************5.����ְ����Ϣ************" << endl;
		cout << " ************6.���ձ������************" << endl;
		cout << " ************7.��������ĵ�************" << endl;
		cout << "*****************************************" << endl;
		//��ȡ�û�ѡ��
		int input;
		cout << "��������Ҫʹ�õĹ�������Ӧ�����-->";
		do
		{
			cin >> input;
		}while (input < 0 || input>7);
		//��ѡ����������Ӧ����
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