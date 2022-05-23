#pragma once
#include <iostream>
using namespace std;
class CMyPoint
{
private:
	int x;
	int y;
public:
	CMyPoint();
	~CMyPoint();
	CMyPoint(const int x, const int y); //인자가 있는 생성자
	CMyPoint(const CMyPoint& pt); //복사 생성자
	CMyPoint(CMyPoint&& pt) noexcept;
	friend ostream& operator<<(ostream& out, CMyPoint& pt);
	bool operator<(const CMyPoint& pt);
	bool operator>(const CMyPoint& pt);

};
