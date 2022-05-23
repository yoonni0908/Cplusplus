#include "Customer2.h"
#include "TV.h"
#include "Vegetable.h"
#include <iostream>
using namespace std;

Customer2::Customer2(const string& name, const int& number)
	:m_name(name), m_number(number)
{
}

Customer2::~Customer2()
{
}

void Customer2::buy(unique_ptr<Product> item)
{
	//if (m_count < m_number) {
	//	items[m_count++] = move(item); //unique포인터는 그대로 대입할수 x -> r-value로 만들어주는 move()로 이동시킴
	//}
	items.push_back(move(item));
}

string Customer2::getName() const
{
	return m_name;
}

int Customer2::getCount() const
{
	return items.size();
}

void Customer2::showlist() const
{
	cout << "고객이름 : " << m_name << endl;
	cout << "구매개수 : " << items.size() << endl;
	int price = 0; //총구매한 금액 변수 초기화
	for (auto it = items.begin(); it != items.end(); it++) {
		(*it)->show();
		price += (*it)->getPrice();
	}
	//for (size_t i = 0; i < m_count; i++) {
	//	items[i]->show(); //부모타입 호출-> 가리키고 있는 객체 호출
	//	price += items[i]->getPrice(); //가격정보 누적
	//}
	cout << "총 구매 금액 : " << price << endl; //가격정보 총액 -> 판매가격 총액
}

void Customer2::showTVlist() const
{
	for (size_t i = 0; i < items.size(); i++) {
		TV* tv = dynamic_cast<TV*>(items[i].get()); //items[i]는 Product타입 -> TV*로 형 변환되서 반환
		if (tv != nullptr)
			items[i]->show();
	}

}

void Customer2::showVegetablelist() const
{
	for (size_t i = 0; i < items.size(); i++) {
		Vegetable* vegetable = dynamic_cast<Vegetable*>(items[i].get());
		if (vegetable != nullptr)
			items[i]->show();
	}
}

