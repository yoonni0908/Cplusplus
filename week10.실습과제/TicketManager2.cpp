#include "TicketManager2.h"
#include "AdvancedTicket.h"
#include "GeneralTicket.h"
#include <iostream>

using namespace std;

TicketManager2::TicketManager2(const string& name, const int number)
	:m_name(name), totalNumber(number), ticket(make_unique<unique_ptr<Ticket>[]>(totalNumber))
{
}

//그냥 포인터를 유니크 포인터로 형변환
void TicketManager2::buy(Ticket* t)
{
	if (count < totalNumber) {
		ticket[count++] = unique_ptr<Ticket>(t);
		return;
	}
	delete t;
}
//unique_ptr를 인자로 받는 buy 함수 (오버로딩)
void TicketManager2::buy(unique_ptr<Ticket> t)
{
	if (count < totalNumber) {
		ticket[count++] = move(t);
		return;
	}
	//delete t;가 필요없음
}

void TicketManager2::show() const
{
	double totalprice = 0;
	cout << "-------- 티켓 예약 현황 ---------" << endl << endl;
	cout << "총 예약 매수 : " << count << endl;
	cout << "--------------------------------" << endl;
	for (size_t i = 0; i < count; i++) {
		ticket[i]->show();
		totalprice += ticket[i]->getPrice();
	}
	cout << "--------------------------------" << endl;
	cout << "총 예약 금액 : " << totalprice << endl;
	cout << "--------------------------------" << endl;

}

void TicketManager2::showGeneralTicket(const bool& card)
{
	double totalprice = 0;
	cout << "-------- 일반 예약 현황 ----------" << endl << endl;
	cout << "카드 결제 여부 : " << card << endl;
	cout << "--------------------------------" << endl;
	for (size_t i = 0; i < count; i++) {
		GeneralTicket* t = dynamic_cast<GeneralTicket*>(ticket[i].get());
		if (t != nullptr) {
			if (t->getPayByCredit() == card) {
				t->show();
				totalprice += ticket[i]->getPrice();
			}
		}
	}
	cout << "---------------------------------" << endl;
	cout << "총 예약 금액 : " << totalprice << endl;
	cout << "---------------------------------" << endl;
}

void TicketManager2::showAdvancedTicket()
{
	double totalprice = 0;
	cout << "-------- 사전 예약 현황 ----------" << endl << endl;
	cout << "--------------------------------" << endl;
	for (size_t i = 0; i < count; i++) {
		AdvancedTicket* t= dynamic_cast<AdvancedTicket*>(ticket[i].get());
		if (t != nullptr) {
			
				t->show();
				totalprice += ticket[i]->getPrice();
			
		}
	}
	cout << "---------------------------------" << endl;
	cout << "총 예약 금액 : " << totalprice << endl;
	cout << "---------------------------------" << endl;
}

ostream& operator<<(ostream& out, const TicketManager2& manager)
{
	manager.show();
	return out;
	//전역함수에서 멤버를 접근하고 싶다면 friend를 해줄 수 있다
}
