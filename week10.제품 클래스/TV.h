#pragma once
#include "Product.h"
class TV : public Product //Product ��ӹ���
{
private:
	int m_size; //������ ���� �߰�
public:
	TV(const string& name, const int& price, const int& size); //�̸�, ����, ������ 
	~TV();
	int getPrice() const; //TV ���� - �θ�� �������� �ٸ��� ȣ��
	void show() const; //�θ�� �ٸ��� ȣ��
};

