#pragma once
#include <memory>
using namespace std;
class ArrayData
{
protected:
	//double* data = nullptr; //�迭
	unique_ptr<double[]> data;
	//shared_ptr<double[]> data;
	int capacity;  //�뷮����(�迭ũ��)
	int used;	//count�ϱ� ����
public:
	ArrayData();
	ArrayData(const int& capacity, const int& used = 0);
	ArrayData(ArrayData& arr);
	ArrayData(ArrayData&& arr) noexcept;
	~ArrayData();
	void addElement(const double& num);  //�迭�� ������ ����
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

	double& operator[](size_t num); //�迭 ������
	const double& operator[](size_t num) const;
	friend ostream& operator<<(ostream& out, const ArrayData& arr); //cout ���
};

//ostream& operator<<(ostream& out, const ArrayData& arr);

