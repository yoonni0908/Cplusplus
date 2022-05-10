#pragma once
#include <string>
#include "Ticket.h"
using std::string;
using std::ostream;
using namespace std;

class TicketManager
{
private:
	string m_name;  //������
	int totalNumber; //�� Ƽ�� ����
	Ticket** ticket = nullptr;
	int count = 0;  // ���� �� Ƽ��
public:
	TicketManager() = delete; //����Ʈ ������ ����� ����
	~TicketManager();
	TicketManager(const string& name, const int number);
	void buy(Ticket* t);
	void show() const;
	// �� �ٱ��Ͽ� ��Ƴ���, ���ϴ� �ν��Ͻ��� ��� ���
	void showGeneralTicket(const bool& card);
	void showAdvancedTicket();
	//friend ostream& operator<<(ostream& out, const TicketManager& manager);
};
ostream& operator<<(ostream& out, const TicketManager& manager);

