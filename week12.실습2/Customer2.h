#pragma once
#include <string>
#include "Product.h"
#include <memory>
#include <vector>
using std::string;
using std::unique_ptr;
using std::vector;

class Customer2  // ��ǰ�� ������ �� Ŭ����
{
private:
	string m_name; // �� �̸�
	int m_number = 0; // ������ �� �ִ� ��ǰ ��
	int m_count = 0; // ������ ������ ��ǰ
	//unique_ptr<unique_ptr<Product>[]> items;
	vector<unique_ptr<Product>> items; //�迭�� ũ�⿡�� �����ο� ���屸��
public:
	Customer2(const string& name, const int& number);
	~Customer2();
	void buy(unique_ptr<Product> item);
	string getName() const;
	int getCount() const;
	void showlist() const;
	void showTVlist() const;
	void showVegetablelist() const;
};