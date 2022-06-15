#pragma once
class Ticket
{
protected:
	static inline int count = 0; // inline 키워드로 클래스 내부 초기화 가능
	int number; //자동으로 부여 - 객체 생성할때마다 자동 증가 count
	double price;
public:
	Ticket() = default;
	~Ticket() = default;
	Ticket(const double& price);
	int getNumber() const;  //티켓번호 반환
	double getPrice() const;  //티켓 가격 반환
	void setPrice(const double& price); //티켓정보 바꿔줌
	void show() const;  //결과 출력
};

