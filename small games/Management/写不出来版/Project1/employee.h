#pragma once
#include<iostream>
#include<string>

using namespace std;

class employee
{
public :
	void modifyName(string name);//�޸�����
	virtual void modifyPosition(int position) = 0;//�޸�ְλ
	virtual void showPosition() {};//չʾְλ�͹�������
protected:
	int m_number{};
	string m_name;
	int m_position{};
};


//�ڸı�ְλ��ϣ�������´���һ����Ӧְλ��ʵ������
//Ҳ������Ҫд�������캯������ԭ�еĲ�ͬ��Ķ���
//������һ���µ�ְλ���͵Ķ�����Ҫ������ţ�����
//ͬʱ�ٰ�ԭְλ�Ķ���ɾ��
//���������Ķ���Ĵ�����Ҫ��ָ����ά��