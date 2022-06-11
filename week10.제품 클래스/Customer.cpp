#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(const string& name, const int& number)
	:m_name(name), m_number(number)
{
	if (m_number > 0)
		items = new Product * [m_number]; //�����Ҵ�
	else
		items = nullptr;
}

Customer::~Customer()
{
	if (items != nullptr) {
		for (size_t i = 0; i < m_count; i++)
			delete items[i];
		delete[] items;
	}
}

void Customer::buy(Product* item)
{
	if (m_count < m_number) {
		items[m_count++] = item; //item�� ���� ��ü ����
	}
}

string Customer::getName() const
{
	return m_name;
}

int Customer::getCount() const
{
	return m_count;
}

void Customer::showlist() const
{
	cout << "���̸� : " << m_name << endl;
	cout << "���Ű��� : " << m_count << endl;
	int price = 0; //�ѱ����� �ݾ� ���� �ʱ�ȭ
	for (size_t i = 0; i < m_count; i++) {
		items[i]->show(); //�θ�Ÿ�� ȣ��-> ����Ű�� �ִ� ��ü ȣ��
		price += items[i]->getPrice(); //�������� ����
	}
	cout << "�� ���� �ݾ� : " << price << endl; //�������� �Ѿ� -> �ǸŰ��� �Ѿ�
}

//		[0]	0x00e7120d {Project81.exe!TV::getPrice(void)const }	void *
//		[1]	0x00e7125d {Project81.exe!TV::show(void)const }	void *
