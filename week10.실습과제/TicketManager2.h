#pragma once
#include <string>
#include <iostream>
#include "Ticket.h"
#include <memory>
using namespace std;
class TicketManager2
{
private:
	string m_name; //������
	int totalNumber; //�� Ƽ�� ����
	unique_ptr<unique_ptr<Ticket>[]> ticket = nullptr;
	int count = 0; //���� �� Ƽ��
public:
	TicketManager2() = delete; //����Ʈ ������ ����� ����
	TicketManager2(const string& name, const int number);
	void buy(Ticket* t);
	void buy(unique_ptr<Ticket> t);
	void show() const;
	//�� �ٱ��� ��Ƴ���, ���ϴ� �ν��Ͻ��� ��� ���
	void showGeneralTicket(const bool& card);
	void showAdvancedTicket();

};
ostream& operator<<(ostream& out, const TicketManager2& manager);

