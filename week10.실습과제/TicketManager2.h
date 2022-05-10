#pragma once
#include <string>
#include <iostream>
#include "Ticket.h"
#include <memory>
using namespace std;
class TicketManager2
{
private:
	string m_name; //공연명
	int totalNumber; //총 티켓 개수
	unique_ptr<unique_ptr<Ticket>[]> ticket = nullptr;
	int count = 0; //실제 판 티켓
public:
	TicketManager2() = delete; //디폴트 생성자 명시적 삭제
	TicketManager2(const string& name, const int number);
	void buy(Ticket* t);
	void buy(unique_ptr<Ticket> t);
	void show() const;
	//한 바구니 담아놓고, 원하는 인스턴스만 골라서 출력
	void showGeneralTicket(const bool& card);
	void showAdvancedTicket();

};
ostream& operator<<(ostream& out, const TicketManager2& manager);

