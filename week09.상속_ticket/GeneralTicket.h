#pragma once
#include "Ticket.h"
class GeneralTicket:public Ticket  //현장에서 판매하는 티켓
{
private:
	bool payByCredit; //카드-true, 현금-false
public:
	GeneralTicket() = default;
	GeneralTicket(const double& price, const bool& payByCredit);
	~GeneralTicket() = default;
	double getPrice() const; //payByCredit에 따라 가격정보 달라짐
	bool getPayByCredit() const;
	void show() const;
};

