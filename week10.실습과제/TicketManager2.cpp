#include "TicketManager2.h"
#include "AdvancedTicket.h"
#include "GeneralTicket.h"
#include <iostream>

using namespace std;

TicketManager2::TicketManager2(const string& name, const int number)
	:m_name(name), totalNumber(number), ticket(make_unique<unique_ptr<Ticket>[]>(totalNumber))
{
}

//�׳� �����͸� ����ũ �����ͷ� ����ȯ
void TicketManager2::buy(Ticket* t)
{
	if (count < totalNumber) {
		ticket[count++] = unique_ptr<Ticket>(t);
		return;
	}
	delete t;
}
//unique_ptr�� ���ڷ� �޴� buy �Լ� (�����ε�)
void TicketManager2::buy(unique_ptr<Ticket> t)
{
	if (count < totalNumber) {
		ticket[count++] = move(t);
		return;
	}
	//delete t;�� �ʿ����
}

void TicketManager2::show() const
{
	double totalprice = 0;
	cout << "-------- Ƽ�� ���� ��Ȳ ---------" << endl << endl;
	cout << "�� ���� �ż� : " << count << endl;
	cout << "--------------------------------" << endl;
	for (size_t i = 0; i < count; i++) {
		ticket[i]->show();
		totalprice += ticket[i]->getPrice();
	}
	cout << "--------------------------------" << endl;
	cout << "�� ���� �ݾ� : " << totalprice << endl;
	cout << "--------------------------------" << endl;

}

void TicketManager2::showGeneralTicket(const bool& card)
{
	double totalprice = 0;
	cout << "-------- �Ϲ� ���� ��Ȳ ----------" << endl << endl;
	cout << "ī�� ���� ���� : " << card << endl;
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
	cout << "�� ���� �ݾ� : " << totalprice << endl;
	cout << "---------------------------------" << endl;
}

void TicketManager2::showAdvancedTicket()
{
	double totalprice = 0;
	cout << "-------- ���� ���� ��Ȳ ----------" << endl << endl;
	cout << "--------------------------------" << endl;
	for (size_t i = 0; i < count; i++) {
		AdvancedTicket* t= dynamic_cast<AdvancedTicket*>(ticket[i].get());
		if (t != nullptr) {
			
				t->show();
				totalprice += ticket[i]->getPrice();
			
		}
	}
	cout << "---------------------------------" << endl;
	cout << "�� ���� �ݾ� : " << totalprice << endl;
	cout << "---------------------------------" << endl;
}

ostream& operator<<(ostream& out, const TicketManager2& manager)
{
	manager.show();
	return out;
	//�����Լ����� ����� �����ϰ� �ʹٸ� friend�� ���� �� �ִ�
}
