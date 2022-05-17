#pragma once
#include <memory>
using namespace std;
template<typename T>
class ArrayData
{
protected:
	//double* data = nullptr; //�迭
	unique_ptr<T[]> data;
	//shared_ptr<double[]> data;
	int capacity;  //�뷮����(�迭ũ��)
	int used;	//count�ϱ� ����
public:
	ArrayData();
	ArrayData(const int& capacity, const int& used = 0);
	ArrayData(ArrayData& arr);
	ArrayData(ArrayData&& arr) noexcept;
	~ArrayData();
	void addElement(const T& num);  //�迭�� ������ ����
	bool full() const;
	void emptyArray();
	void showData() const;
	int getCapacity() const {  //�ζ���
		return this->capacity;
	};
	int getUsed() const {   //�ζ���
		return this->used;
	};
	void setUsed() {
		used++;
	}

	//������ ������ : �����ε�
	ArrayData& operator=(const ArrayData& rhs);
	ArrayData& operator=(ArrayData&& rhs) noexcept; //�̵� ���� ������

	T& operator[](size_t num); //�迭 ������
	const T& operator[](size_t num) const;
	template<typename T1>
	friend ostream& operator<<(ostream& out, const ArrayData<T1>& arr);
};

//ostream& operator<<(ostream& out, const ArrayData& arr);

#include "ArrayDataDef.h"