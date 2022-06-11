#include "Vegetable.h"
#include <iostream>
using namespace std;

Vegetable::Vegetable(const string& name, const int& price, const string& origin, const int& weight)
	:Product(name, price), m_origin(origin), m_weight(weight)
{
}

Vegetable::~Vegetable()
{
}

int Vegetable::getPrice() const
{
	return m_price * m_weight;
}

void Vegetable::show() const
{
	Product::show();
	cout << "������ : " << m_origin << endl;
	cout << "�ǸŰ��� : " << getPrice() << endl;
	cout << "---------------------------------" << endl;
}
