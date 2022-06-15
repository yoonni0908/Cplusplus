#pragma once
#include "Ticket.h"
class AdvancedTicket:public Ticket  //사전예약티켓--예약일수에 따라 가격결정
{
private:
	int advanceDays;
public:
	AdvancedTicket() = default;
	AdvancedTicket(const double& price, const int& advanceDays);
	~AdvancedTicket() = default;
	double getPrice() const;
	int getAdvanceDays() const;
	void show() const;
};
/*30일전 50%할인
  20일전 30%할인
  10일전 10%할인*/

