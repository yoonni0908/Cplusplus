#pragma once
#include "Ticket.h"
class GeneralTicket:public Ticket  //���忡�� �Ǹ��ϴ� Ƽ��
{
private:
	bool payByCredit; //ī��-true, ����-false
public:
	GeneralTicket() = default;
	GeneralTicket(const double& price, const bool& payByCredit);
	~GeneralTicket() = default;
	double getPrice() const; //payByCredit�� ���� �������� �޶���
	bool getPayByCredit() const;
	void show() const;
};

