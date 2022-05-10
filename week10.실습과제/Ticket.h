#pragma once
class Ticket
{
protected:
	static inline int count = 0;
	int number;
	double price;
public:
	//������
	Ticket() = default;
	Ticket(const double& price);
	//�Ҹ���
	virtual ~Ticket() = default;
	int getNumber() const;
	virtual double getPrice() const = 0;
	void setPrice(const double& price);
	virtual void show() const;
};
