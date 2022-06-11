#pragma once
#include <string>
#include "Product.h"
using std::string;

class Customer  // 제품을 구매할 고객 클래스
{
private:
	string m_name; // 고객 이름
	int m_number = 0; // 구매할 수 있는 제품 수
	int m_count = 0; // 실제로 구매한 제품
	Product** items; 
	// Product* items[10]; 객체 10개까지 저장, 포인터 타입 - 다형성 활용, 자식 객체가 온전히 남아있도록/ 동적 - 더블타입
public:
	Customer(const string& name, const int& number);
	~Customer();
	void buy(Product* item); //고객이 구매하는 함수-함수 오버로딩
	string getName() const;
	int getCount() const;
	void showlist() const;
};

