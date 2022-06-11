#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(const string& name, const int& number)
	:m_name(name), m_number(number)
{
	if (m_number > 0)
		items = new Product * [m_number]; //동적할당
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
		items[m_count++] = item; //item에 들어온 객체 저장
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
	cout << "고객이름 : " << m_name << endl;
	cout << "구매개수 : " << m_count << endl;
	int price = 0; //총구매한 금액 변수 초기화
	for (size_t i = 0; i < m_count; i++) {
		items[i]->show(); //부모타입 호출-> 가리키고 있는 객체 호출
		price += items[i]->getPrice(); //가격정보 누적
	}
	cout << "총 구매 금액 : " << price << endl; //가격정보 총액 -> 판매가격 총액
}

//		[0]	0x00e7120d {Project81.exe!TV::getPrice(void)const }	void *
//		[1]	0x00e7125d {Project81.exe!TV::show(void)const }	void *
