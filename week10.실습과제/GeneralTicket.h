#pragma once
#include "Ticket.h"
class GeneralTicket :
	public Ticket
{
private:
	bool payByCredit;
public:
	// 持失切
	GeneralTicket() = default;
	GeneralTicket(const double& price, const bool& payByCredit);
	~GeneralTicket() = default;
	// 社瑚切
	double getPrice() const;
	bool getPayByCredit() const;
	void show() const;
};