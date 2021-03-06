#include "Ticket.h"
#include <iostream>
using namespace std;

Ticket::Ticket(const double& price):number(++count), price(price)
{
}

int Ticket::getNumber() const
{
	return number;
}

double Ticket::getPrice() const
{
	return price;
}

void Ticket::setPrice(const double& price)
{
	this->price = price;
}

void Ticket::show() const
{
	cout << "티켓번호 : " << getNumber() << endl;
	cout << "가격정보 : " << getPrice() << endl;
}
