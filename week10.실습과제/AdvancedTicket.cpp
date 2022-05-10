#include "AdvancedTicket.h"
#include <iostream>
using namespace std;

AdvancedTicket::AdvancedTicket(const double& price, const int& advanceDays)
	:Ticket(price), advanceDays(advanceDays) {
}

double AdvancedTicket::getPrice() const
{
	if (advanceDays >= 30)
		return price * 0.5;
	else if (advanceDays >= 20)
		return price * 0.7;
	else if (advanceDays >= 10)
		return price * 0.9;
	else
		return price;
}

int AdvancedTicket::getAdvanceDays() const
{
	return advanceDays;
}

void AdvancedTicket::show() const
{
	Ticket::show();
	cout << "���������� : " << getAdvanceDays() << endl;
	cout << "���ұݾ� : " << getPrice() << endl;
}
