#pragma once
#include "ArrayData.h"
#include <iostream>
using namespace std;
template<typename T>
ArrayData<T>::ArrayData() :ArrayData(3)  //디폴트 생성자
{
}

template<typename T>
ArrayData<T>::ArrayData(const int& capacity, const int& used) : capacity(capacity), used(used)
{
	cout << "생성자" << endl;
	//data = new double[this->capacity];  //data는 capacity만큼 생성
	data = make_unique<T[]>(this->capacity);
	//data = shared_ptr<double[]>(new double[this->capacity]);
}

template<typename T>
ArrayData<T>::ArrayData(ArrayData& arr)
	:ArrayData(arr.capacity, arr.used)
{
	cout << "복사생성자" << endl;
	for (size_t i = 0; i < used; i++) {  //ArrayData 내용복사
		data[i] = arr.data[i];   //다른 메모리 같은 값
	}
}

template<typename T>
ArrayData<T>::ArrayData(ArrayData&& arr) noexcept
	:capacity(arr.capacity), used(arr.used), data(move(arr.data))
{
	cout << "이동생성자" << endl;
	//arr.data = nullptr;
}


template<typename T>
ArrayData<T>::~ArrayData()
{
	/*if (data != nullptr)
		delete[] data;
	data = nullptr;*/
}

template<typename T>
void ArrayData<T>::addElement(const T& num)
{
	if (!full()) //full이 아닐때
		data[used++] = num;  //증가-다음번의 방을 가리킴
	else
		cout << "빈방이 없음\n";  //full일때
}

template<typename T>
bool ArrayData<T>::full() const  //배열이 꽉차있을때
{
	return this->capacity == this->used; //true or false반환
}

template<typename T>
void ArrayData<T>::emptyArray() //배열 내용 지우기
{
	this->used = 0;  //used를 0으로
}

template<typename T>
void ArrayData<T>::showData() const
{
	for (size_t i = 0; i < used; i++)
		cout << data[i] << " ";  //들어가있는 data 그대로 출력
	cout << endl;
}

template<typename T>
ArrayData<T>& ArrayData<T>::operator=(const ArrayData<T>& rhs) //대입 연산자 - 깊은 복사 수행
{
	cout << "대입연산자" << endl;  // a = b;
	if (this == &rhs)
		return *this;
	this->capacity = rhs.capacity;
	this->used = rhs.used;
	/*if (data != nullptr)
		delete[] data;
	data = new double[capacity];*/
	data.reset(new double[capacity]); //unique_ptr
	for (size_t i = 0; i < used; i++) {
		data[i] = rhs.data[i];  //방대 방으로 복사하는 작업
		//*(data + i) = *(rhs.data + i);
	}
	return *this;
}

template<typename T>
ArrayData<T>& ArrayData<T>::operator=(ArrayData<T>&& rhs) noexcept  //얕은 복사 수행
{
	cout << "이동대입연산자" << endl;
	this->capacity = rhs.capacity;
	this->used = rhs.used;
	data = move(rhs.data); //unique_ptr
	/*if (data != nullptr)
		delete[] data;
	data = rhs.data;*/
	rhs.data = nullptr;
	return *this;
}

template<typename T>
T& ArrayData<T>::operator[](size_t num)  //배열 연산자/ 일반 객체 호출 - 변경 시킬 수 o
{
	if (num >= 0 && num < capacity) {  //참조 범위
		return data[num];
	}
	else {
		cout << "배열 참조 오류" << endl;
		exit(0);
	}
}

template<typename T>
const T& ArrayData<T>::operator[](size_t num) const //const 객체 호출 - 변경 x
{
	if (num >= 0 && num < used) {
		return data[num];
	}
	else {
		cout << "배열 참조 오류" << endl;
		exit(0);
	}
}

template<typename T1>
ostream& operator<<(ostream& out, const ArrayData<T1>& arr) {
	for (size_t i = 0; i < arr.getUsed(); i++) {
		//out << arr[i] << "\t";
		out << arr.data[i] << "\t";
	}
	out << endl;
	return out;
}
