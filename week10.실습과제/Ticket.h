#pragma once
class Ticket
{
protected:
	static inline int count = 0;
	int number;
	double price;
public:
	//持失切
	Ticket() = default;
	Ticket(const double& price);
	//社瑚切
	virtual ~Ticket() = default;
	int getNumber() const;
	virtual double getPrice() const = 0;
	void setPrice(const double& price);
	virtual void show() const;
};
