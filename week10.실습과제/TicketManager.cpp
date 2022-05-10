#include "TicketManager.h"
#include "AdvancedTicket.h"
#include "GeneralTicket.h"
#include <iostream>

using namespace std;

TicketManager::~TicketManager()
{
	if (ticket != nullptr) {
		for (size_t i = 0; i < count; i++) {
			delete ticket[i];
		}
		delete[] ticket;
	}
	ticket = nullptr;
}

TicketManager::TicketManager(const string& name, const int number)
	:m_name(name), totalNumber(number)//,ticket(new Ticket* [totalNumber])
{
	if (totalNumber > 0)
		ticket = new Ticket * [totalNumber];
}

void TicketManager::buy(Ticket* t)
{
	if (count < totalNumber) {
		ticket[count++] = t;
		return;
	}
	delete t;
}

void TicketManager::show() const
{
	double totalprice = 0;
	cout << "-------- 티켓 예약 현황 --------" << endl << endl;
	cout << "총 예약 매수 : " << count << endl;
	cout << "------------------------------" << endl;
	for (size_t i = 0; i < count; i++) {
		ticket[i]->show();
		totalprice += ticket[i]->getPrice();
	}
	cout << "------------------------------" << endl;
	cout << "총 예약 금액 : " << totalprice << endl;
	cout << "------------------------------" << endl;

}

void TicketManager::showGeneralTicket(const bool& card)
{
	double totalprice = 0;
	cout << "-------- 일반 예약 현황 --------" << endl << endl;
	cout << "카드 결제 여부 : " << card << endl;
	cout << "------------------------------" << endl;
	for (size_t i = 0; i < count; i++) {
		GeneralTicket* t = dynamic_cast<GeneralTicket*>(ticket[i]);
		if (t != nullptr) {
			if (t->getPayByCredit() == card) {
				t->show();
				totalprice += ticket[i]->getPrice();
			}
		}
	}
	cout << "------------------------------" << endl;
	cout << "총 예약 금액 : " << totalprice << endl;
	cout << "------------------------------" << endl;
}

void TicketManager::showAdvancedTicket()
{
	double totalprice = 0;
	cout << "-------- 사전 예약 현황 --------" << endl << endl;
	cout << "------------------------------" << endl;
	for (size_t i = 0; i < count; i++) {
		AdvancedTicket* t = dynamic_cast<AdvancedTicket*>(ticket[i]);
		if (t != nullptr) {
			if (t != nullptr) {
				t->show();
				totalprice += ticket[i]->getPrice();
			}
		}
	}
	cout << "------------------------------" << endl;
	cout << "총 예약 금액 : " << totalprice << endl;
	cout << "------------------------------" << endl;

}

ostream& operator<<(ostream& out, const TicketManager& manager)
{
	manager.show();
	return out;
}
