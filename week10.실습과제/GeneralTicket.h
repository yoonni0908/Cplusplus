#pragma once
#include "Ticket.h"
class GeneralTicket :
	public Ticket
{
private:
	bool payByCredit;
public:
	// ������
	GeneralTicket() = default;
	GeneralTicket(const double& price, const bool& payByCredit);
	~GeneralTicket() = default;
	// �Ҹ���
	double getPrice() const;
	bool getPayByCredit() const;
	void show() const;
};