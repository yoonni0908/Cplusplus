#include "Customer2.h"
#include <iostream>
using namespace std;

Customer2::Customer2(const string& name, const int& number)
	:m_name(name), m_number(number), items(make_unique<unique_ptr<Product>[]>(m_number))
{
}

Customer2::~Customer2()
{
}

void Customer2::buy(unique_ptr<Product> item)
{
	if (m_count < m_number) {
		items[m_count++] = move(item); //unique�����ʹ� �״�� �����Ҽ� x -> r-value�� ������ִ� move()�� �̵���Ŵ
	}
}

string Customer2::getName() const
{
	return m_name;
}

int Customer2::getCount() const
{
	return m_count;
}

void Customer2::showlist() const
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
