#include "ArrayDataSmart.h"
#include <iostream>
using namespace std;

ArrayDataSmart::ArrayDataSmart()
	:ArrayDataSmart(3) //디폴트 생성자 - 똑같이 3개 만듬
{
}

ArrayDataSmart::ArrayDataSmart(ArrayDataSmart& arr) //복사 생성자
	:ArrayData(arr), usedB(arr.usedB), backdata(make_unique<double[]>(arr.capacity)) //부모꺼 arr 그대로 넘김, 내꺼만 초기화
{                                                                              //capacity 사이즈 만큼 할당
	cout << "ArrayData 복사생성자" << endl;
	for (size_t i = 0; i < usedB; i++) { //방대방으로 복사
		backdata[i] = arr.backdata[i];
	}
}

ArrayDataSmart::ArrayDataSmart(ArrayDataSmart&& arr) noexcept //이동 생성자
	:ArrayData(move(arr)), usedB(arr.usedB), backdata(move(arr.backdata)) //이동생성자 이므로 부모 arr를 move 시킴
{
	cout << "ArrayDataSmart 이동생성자" << endl;
}

ArrayDataSmart::ArrayDataSmart(const int& capacity, const int& used) //인자가 있는 생성자
	:ArrayData(capacity, used), usedB(0), backdata(make_unique<double[]>(capacity)) //capacity, used 값 부모에서 넘겨줌
{                                           //backdata는 capacity 만큼 초기화 시켜줌
	cout << "ArrayDataSmart 생성자" << endl;
}

ArrayDataSmart::~ArrayDataSmart()
{
	cout << "ArrayDataSmart 소멸자" << endl;
}

void ArrayDataSmart::backup() { //백업 기능
	if (backdata != nullptr) { //공간할당 받은게 있다면
		usedB = used;
		for (size_t i = 0; i < usedB; i++) {
			backdata[i] = data[i];  //부모에 해당하는 값이 data, 사용한 개수 만큼 그대로 백업
		}
	}
}

void ArrayDataSmart::restore() //원상복귀
{
	if (backdata != nullptr) {
		used = usedB; //백업과 반대
		for (size_t i = 0; i < usedB; i++) {
			data[i] = backdata[i];
		}
	}
}

ArrayDataSmart& ArrayDataSmart::operator=(const ArrayDataSmart& rhs)
{
	cout << "ArrayDataSmart 대입연산자" << endl;
	if (this == &rhs) { //같은 값 대입 -> 주소값이 같음
		return *this; 
	}
	ArrayData::operator=(rhs); //같지 x -> 부모 클래스 operator호출
	usedB = rhs.usedB; //내꺼에 해당하는 식 초기화
	backdata = make_unique<double[]>(rhs.capacity);
	for (size_t i = 0; i < usedB; i++) {
		backdata[i] = rhs.backdata[i]; //방대 방으로 복사
	}
	return *this;
}

ArrayDataSmart& ArrayDataSmart::operator=(ArrayDataSmart&& rhs) noexcept
{
	cout << "ArrayDataSmart 이동대입연산자" << endl;
	if (this == &rhs) {
		return *this;
	}
	ArrayData::operator=(move(rhs));
	usedB = rhs.usedB;
	backdata = move(rhs.backdata); //

	return *this;
}
