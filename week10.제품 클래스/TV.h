#pragma once
#include "Product.h"
class TV : public Product //Product 상속받음
{
private:
	int m_size; //사이즈 정보 추가
public:
	TV(const string& name, const int& price, const int& size); //이름, 가격, 사이즈 
	~TV();
	int getPrice() const; //TV 세일 - 부모와 가격정보 다르게 호출
	void show() const; //부모와 다르게 호출
};

