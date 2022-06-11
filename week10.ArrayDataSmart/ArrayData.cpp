#include "ArrayData.h"
#include <iostream>
using namespace std;
ArrayData::ArrayData() :ArrayData(3)  //����Ʈ ������
{
}

ArrayData::ArrayData(const int& capacity, const int& used) : capacity(capacity), used(used)
{
	cout << "������" << endl;
	//data = new double[this->capacity];  //data�� capacity��ŭ ����
	data = make_unique<double[]>(this->capacity);
	//data = shared_ptr<double[]>(new double[this->capacity]);
}

ArrayData::ArrayData(ArrayData& arr)
	:ArrayData(arr.capacity, arr.used)
{
	cout << "���������" << endl;
	for (size_t i = 0; i < used; i++) {  //ArrayData ���뺹��
		data[i] = arr.data[i];   //�ٸ� �޸� ���� ��
	}
}

ArrayData::ArrayData(ArrayData&& arr) noexcept
	:capacity(arr.capacity), used(arr.used), data(move(arr.data))
{
	cout << "�̵�������" << endl;
	//arr.data = nullptr;
}


ArrayData::~ArrayData()
{
	/*if (data != nullptr)
		delete[] data;
	data = nullptr;*/
}

void ArrayData::addElement(const double& num)
{
	if (!full()) //full�� �ƴҶ�
		data[used++] = num;  //����-�������� ���� ����Ŵ
	else
		cout << "����� ����\n";  //full�϶�
}

bool ArrayData::full() const  //�迭�� ����������
{
	return this->capacity == this->used; //true or false��ȯ
}

void ArrayData::emptyArray() //�迭 ���� �����
{
	this->used = 0;  //used�� 0����
}

void ArrayData::showData() const
{
	for (size_t i = 0; i < used; i++)
		cout << data[i] << " ";  //���ִ� data �״�� ���
	cout << endl;
}

ArrayData& ArrayData::operator=(const ArrayData& rhs) //���� ������ - ���� ���� ����
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

ArrayData& ArrayData::operator=(ArrayData&& rhs) noexcept  //���� ���� ����
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

double& ArrayData::operator[](size_t num)  //�Ϲ� ��ü ȣ�� - ���� ��ų �� o
{
	if (num >= 0 && num < capacity) {  //���� ����
		return data[num];
	}
	else {
		cout << "�迭 ���� ����" << endl;
		exit(0);
	}
}

const double& ArrayData::operator[](size_t num) const //const ��ü ȣ�� - ���� x
{
	if (num >= 0 && num < used) {
		return data[num];
	}
	else {
		cout << "�迭 ���� ����" << endl;
		exit(0);
	}
}

ostream& operator<<(ostream& out, const ArrayData& arr) {
	for (size_t i = 0; i < arr.getUsed(); i++) {
		//out << arr[i] << "\t";
		out << arr.data[i] << "\t";
	}
	out << endl;
	return out;
}
