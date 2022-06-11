#pragma once
#include <string>
#include "Product.h"
using std::string;

class Customer  // ��ǰ�� ������ �� Ŭ����
{
private:
	string m_name; // �� �̸�
	int m_number = 0; // ������ �� �ִ� ��ǰ ��
	int m_count = 0; // ������ ������ ��ǰ
	Product** items; 
	// Product* items[10]; ��ü 10������ ����, ������ Ÿ�� - ������ Ȱ��, �ڽ� ��ü�� ������ �����ֵ���/ ���� - ����Ÿ��
public:
	Customer(const string& name, const int& number);
	~Customer();
	void buy(Product* item); //���� �����ϴ� �Լ�-�Լ� �����ε�
	string getName() const;
	int getCount() const;
	void showlist() const;
};

