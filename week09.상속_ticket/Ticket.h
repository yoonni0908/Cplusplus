#pragma once
class Ticket
{
protected:
	static inline int count = 0; // inline Ű����� Ŭ���� ���� �ʱ�ȭ ����
	int number; //�ڵ����� �ο� - ��ü �����Ҷ����� �ڵ� ���� count
	double price;
public:
	Ticket() = default;
	~Ticket() = default;
	Ticket(const double& price);
	int getNumber() const;  //Ƽ�Ϲ�ȣ ��ȯ
	double getPrice() const;  //Ƽ�� ���� ��ȯ
	void setPrice(const double& price); //Ƽ������ �ٲ���
	void show() const;  //��� ���
};

