#pragma once
#include "Ticket.h"
class AdvancedTicket :
	public Ticket
{
private:
	int advanceDays;
public:
	//������
	AdvancedTicket() = default;
	AdvancedTicket(const double& price, const int& advanceDays);
	//�Ҹ���
	~AdvancedTicket() = default;
	double getPrice() const;
	int getAdvanceDays() const;
	void show() const;
};
