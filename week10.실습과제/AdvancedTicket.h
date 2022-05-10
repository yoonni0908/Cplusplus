#pragma once
#include "Ticket.h"
class AdvancedTicket :
	public Ticket
{
private:
	int advanceDays;
public:
	//持失切
	AdvancedTicket() = default;
	AdvancedTicket(const double& price, const int& advanceDays);
	//社瑚切
	~AdvancedTicket() = default;
	double getPrice() const;
	int getAdvanceDays() const;
	void show() const;
};
