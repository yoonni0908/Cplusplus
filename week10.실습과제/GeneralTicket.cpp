#include "GeneralTicket.h"
#include <iostream>
using namespace std;
GeneralTicket::GeneralTicket(const double& price, const bool& payByCredit)
	:Ticket(price), payByCredit(payByCredit)
{

}

double GeneralTicket::getPrice() const
{
	if (getPayByCredit())
		return price + price * 0.1;
	return price;
}

bool GeneralTicket::getPayByCredit() const
{
	return payByCredit;
}

void GeneralTicket::show() const
{
	Ticket::show();
	cout << "ī����翩�� : " << boolalpha << getPayByCredit() << endl;
	cout << "���ұݾ� : " << getPrice() << endl;
}
