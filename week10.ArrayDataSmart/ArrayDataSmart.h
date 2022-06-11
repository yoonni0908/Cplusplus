#pragma once
#include "ArrayData.h"
class ArrayDataSmart :
    public ArrayData
{
private:
    unique_ptr<double[]> backdata; //백업받을 저장공간
    int usedB;//몇개의 백업데이터가 있는지 정보 저장
public:
    ArrayDataSmart(); //디폴트 생성자
    ArrayDataSmart(ArrayDataSmart& arr); // 복사 생성자
    ArrayDataSmart(ArrayDataSmart&& arr) noexcept; // 이동 생성자
    ArrayDataSmart(const int& capacity, const int& used = 0); // 인자가 있는 생성자
    ~ArrayDataSmart(); //소멸자
    void backup();  //백업받는 기능을 가진 함수
    void restore();  //백업받았던거 원래 상태로 돌리는 함수
    ArrayDataSmart& operator=(const ArrayDataSmart& rhs);  //대입연산자 오버로딩 
    ArrayDataSmart& operator=(ArrayDataSmart&& rhs) noexcept; //이동대입연산자
};

