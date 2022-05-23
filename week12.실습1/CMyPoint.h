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
	CMyPoint(const int x, const int y); //���ڰ� �ִ� ������
	CMyPoint(const CMyPoint& pt); //���� ������
	CMyPoint(CMyPoint&& pt) noexcept;
	friend ostream& operator<<(ostream& out, CMyPoint& pt);
	bool operator<(const CMyPoint& pt);
	bool operator>(const CMyPoint& pt);

};
