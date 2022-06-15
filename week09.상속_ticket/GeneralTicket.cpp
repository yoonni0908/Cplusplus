#include "GeneralTicket.h"
#include <iostream>
using namespace std;

GeneralTicket::GeneralTicket(const double& price, const bool& payByCredit)
	:Ticket(price), payByCredit(payByCredit)  //Ticket()부모 생성자를 통해 호출
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
	Ticket::show(); //부모 정보 출력
	cout << "카드결제여부 : " << boolalpha << getPayByCredit() << endl;
	cout << "지불금액 : " << getPrice() << endl;
}
