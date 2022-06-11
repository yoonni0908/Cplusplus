#pragma once
#include <string>
using std::string;
class Product
{
protected:
	string m_name;
	int m_price;
public:
	Product(const string& name, const int& price);
	~Product();
	virtual int getPrice() const; //가상함수
	string getName() const;
	virtual void show() const; //가상함수
};

