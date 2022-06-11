#pragma once
#include <memory>
using namespace std;
class ArrayData
{
protected:
	//double* data = nullptr; //배열
	unique_ptr<double[]> data;
	//shared_ptr<double[]> data;
	int capacity;  //용량정보(배열크기)
	int used;	//count하기 위함
public:
	ArrayData();
	ArrayData(const int& capacity, const int& used = 0);
	ArrayData(ArrayData& arr);
	ArrayData(ArrayData&& arr) noexcept;
	~ArrayData();
	void addElement(const double& num);  //배열에 데이터 저장
	bool full() const;
	void emptyArray();
	void showData() const;
	int getCapacity() const {  //인라인
		return this->capacity;
	};
	int getUsed() const {   //인라인
		return this->used;
	};
	void setUsed() {
		used++;
	}

	//연산자 재정의 : 오버로딩
	ArrayData& operator=(const ArrayData& rhs);
	ArrayData& operator=(ArrayData&& rhs) noexcept; //이동 대입 연산자

	double& operator[](size_t num); //배열 연산자
	const double& operator[](size_t num) const;
	friend ostream& operator<<(ostream& out, const ArrayData& arr); //cout 출력
};

//ostream& operator<<(ostream& out, const ArrayData& arr);

