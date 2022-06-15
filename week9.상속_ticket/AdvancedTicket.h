#pragma once
#include "Ticket.h"
class AdvancedTicket:public Ticket  //��������Ƽ��--�����ϼ��� ���� ���ݰ���
{
private:
	int advanceDays;
public:
	AdvancedTicket() = default;
	AdvancedTicket(const double& price, const int& advanceDays);
	~AdvancedTicket() = default;
	double getPrice() const;
	int getAdvanceDays() const;
	void show() const;
};
/*30���� 50%����
  20���� 30%����
  10���� 10%����*/

