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
	cout << "-------- Ƽ�� ���� ��Ȳ --------" << endl << endl;
	cout << "�� ���� �ż� : " << count << endl;
	cout << "------------------------------" << endl;
	for (size_t i = 0; i < count; i++) {
		ticket[i]->show();
		totalprice += ticket[i]->getPrice();
	}
	cout << "------------------------------" << endl;
	cout << "�� ���� �ݾ� : " << totalprice << endl;
	cout << "------------------------------" << endl;

}

void TicketManager::showGeneralTicket(const bool& card)
{
	double totalprice = 0;
	cout << "-------- �Ϲ� ���� ��Ȳ --------" << endl << endl;
	cout << "ī�� ���� ���� : " << card << endl;
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
	cout << "�� ���� �ݾ� : " << totalprice << endl;
	cout << "------------------------------" << endl;
}

void TicketManager::showAdvancedTicket()
{
	double totalprice = 0;
	cout << "-------- ���� ���� ��Ȳ --------" << endl << endl;
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
	cout << "�� ���� �ݾ� : " << totalprice << endl;
	cout << "------------------------------" << endl;

}

ostream& operator<<(ostream& out, const TicketManager& manager)
{
	manager.show();
	return out;
}
