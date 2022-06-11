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
	virtual int getPrice() const; //�����Լ�
	string getName() const;
	virtual void show() const; //�����Լ�
};

