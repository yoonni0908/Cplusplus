#pragma once
#include <string>
#include "Product.h"
#include <memory>
#include <vector>
using std::string;
using std::unique_ptr;
using std::vector;

class Customer2  // 제품을 구매할 고객 클래스
{
private:
	string m_name; // 고객 이름
	int m_number = 0; // 구매할 수 있는 제품 수
	int m_count = 0; // 실제로 구매한 제품
	//unique_ptr<unique_ptr<Product>[]> items;
	vector<unique_ptr<Product>> items; //배열의 크기에서 자유로운 저장구조
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