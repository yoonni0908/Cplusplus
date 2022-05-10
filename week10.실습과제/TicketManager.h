#pragma once
#include <string>
#include "Ticket.h"
using std::string;
using std::ostream;
using namespace std;

class TicketManager
{
private:
	string m_name;  //공연명
	int totalNumber; //총 티켓 개수
	Ticket** ticket = nullptr;
	int count = 0;  // 실제 판 티켓
public:
	TicketManager() = delete; //디폴트 생성자 명시적 삭제
	~TicketManager();
	TicketManager(const string& name, const int number);
	void buy(Ticket* t);
	void show() const;
	// 한 바구니에 담아놓고, 원하는 인스턴스만 골라서 출력
	void showGeneralTicket(const bool& card);
	void showAdvancedTicket();
	//friend ostream& operator<<(ostream& out, const TicketManager& manager);
};
ostream& operator<<(ostream& out, const TicketManager& manager);

