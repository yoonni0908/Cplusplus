#pragma once
#include "Product.h"
class Vegetable:public Product
{
private:
	string m_origin; //원산지 정보
	int m_weight; //무게 정보
public:
	Vegetable(const string& name, const int& price, const string& origin, const int& weight);
	~Vegetable();
	int getPrice() const; //무게에 따른 가격정보 재정의
	void show() const; //재정의
};

