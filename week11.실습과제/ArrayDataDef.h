#pragma once
#include "ArrayData.h"
#include <iostream>
using namespace std;
template<typename T>
ArrayData<T>::ArrayData() :ArrayData(3)  //����Ʈ ������
{
}

template<typename T>
ArrayData<T>::ArrayData(const int& capacity, const int& used) : capacity(capacity), used(used)
{
	cout << "������" << endl;
	//data = new double[this->capacity];  //data�� capacity��ŭ ����
	data = make_unique<T[]>(this->capacity);
	//data = shared_ptr<double[]>(new double[this->capacity]);
}

template<typename T>
ArrayData<T>::ArrayData(ArrayData& arr)
	:ArrayData(arr.capacity, arr.used)
{
	cout << "���������" << endl;
	for (size_t i = 0; i < used; i++) {  //ArrayData ���뺹��
		data[i] = arr.data[i];   //�ٸ� �޸� ���� ��
	}
}

template<typename T>
ArrayData<T>::ArrayData(ArrayData&& arr) noexcept
	:capacity(arr.capacity), used(arr.used), data(move(arr.data))
{
	cout << "�̵�������" << endl;
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
	if (!full()) //full�� �ƴҶ�
		data[used++] = num;  //����-�������� ���� ����Ŵ
	else
		cout << "����� ����\n";  //full�϶�
}

template<typename T>
bool ArrayData<T>::full() const  //�迭�� ����������
{
	return this->capacity == this->used; //true or false��ȯ
}

template<typename T>
void ArrayData<T>::emptyArray() //�迭 ���� �����
{
	this->used = 0;  //used�� 0����
}

template<typename T>
void ArrayData<T>::showData() const
{
	for (size_t i = 0; i < used; i++)
		cout << data[i] << " ";  //���ִ� data �״�� ���
	cout << endl;
}

template<typename T>
ArrayData<T>& ArrayData<T>::operator=(const ArrayData<T>& rhs) //���� ������ - ���� ���� ����
{
	cout << "���Կ�����" << endl;  // a = b;
	if (this == &rhs)
		return *this;
	this->capacity = rhs.capacity;
	this->used = rhs.used;
	/*if (data != nullptr)
		delete[] data;
	data = new double[capacity];*/
	data.reset(new double[capacity]); //unique_ptr
	for (size_t i = 0; i < used; i++) {
		data[i] = rhs.data[i];  //��� ������ �����ϴ� �۾�
		//*(data + i) = *(rhs.data + i);
	}
	return *this;
}

template<typename T>
ArrayData<T>& ArrayData<T>::operator=(ArrayData<T>&& rhs) noexcept  //���� ���� ����
{
	cout << "�̵����Կ�����" << endl;
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
T& ArrayData<T>::operator[](size_t num)  //�迭 ������/ �Ϲ� ��ü ȣ�� - ���� ��ų �� o
{
	if (num >= 0 && num < capacity) {  //���� ����
		return data[num];
	}
	else {
		cout << "�迭 ���� ����" << endl;
		exit(0);
	}
}

template<typename T>
const T& ArrayData<T>::operator[](size_t num) const //const ��ü ȣ�� - ���� x
{
	if (num >= 0 && num < used) {
		return data[num];
	}
	else {
		cout << "�迭 ���� ����" << endl;
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
