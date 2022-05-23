#include <iostream>
#include <string>
#include <vector>
#include "CMyPoint.h"
using namespace std;

template<typename T>
void printArr(vector<T>& v) { //인자로 벡터 전달-레퍼런스 형태
	for (auto it = v.begin(); it!= v.end(); it++) {
		cout << *it << endl; //iterator가 가리키는 값을 출력
	}
	cout << endl;
}

int main() {

	vector<unique_ptr<CMyPoint>> arr;
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));

	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << **it << ""; 
	}

	//vector<CMyPoint*> arr; //벡터의 주소값을 저장
	//arr.push_back(new CMyPoint(10, 10));
	//arr.push_back(new CMyPoint(10, 10));
	//arr.push_back(new CMyPoint(10, 10));
	//for (auto it = arr.begin(); it != arr.end(); it++) {
	//	cout << **it << ""; //주소값이 가리키는 값을 출력
	//	delete* it; //iterator가 가리키는 값(주소값) 삭제
	//}

	
	//내가 만든 데이터 벡터에 저장
	//vector<CMyPoint> arr;
	//for (int i = 0; i < 5; i++) {
	//	//arr.push_back(CMyPoint(i * 10, i * 10)); //r-value 객체
	//	arr.emplace_back(i * 10, i * 10); //생성자 자체 호출
	//	cout << endl << endl;
	//}
	
	
	
	//vector<CMyPoint> arr3(&arr[0], &arr[3]); //범위지정
	//printArr(arr3);
	

	//vector<int> intarr1(10); //방 10개의 벡터 생성
	//cout << intarr1.size() << endl; //10
	//cout << intarr1.capacity() << endl; //10

	//동적할당
	//vector<int> intarr1;
	//for (int i = 0; i < 10; i++) {
	//	intarr1.push_back(i);
	//	cout << intarr1.size() << endl;
	//	cout << intarr1.capacity() << endl; //공간 미리 확보하는 형태
	//	cout << intarr1.data() << endl; //주소값 
	//	cout << endl;
	//}

	//벡터에 데이터 삽입
	//vector<int> arr1({ 1, 2, 3,4, 5 }); //배열 초기화

	//vector<double> arr2;
	//arr2.push_back(10.5); //데이터 삽입
	//arr2.push_back(10.5);
	//arr2.push_back(10.5);
	//arr2.insert(arr2.begin(), 2.5); //포지션 정보를 주어야함

	//printArr(arr1);
	//cout << "===============" << endl;
	//printArr(arr2);
}