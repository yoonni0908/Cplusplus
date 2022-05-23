#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include "CMyPoint.h"
using namespace std;

template<typename T>
void printArr(vector<T>& v) { //인자로 벡터 전달-레퍼런스 형태
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";//iterator가 가리키는 값을 출력
	}
	cout << endl;
}

int main() {

	list<CMyPoint> list2;
	list2.push_back(CMyPoint(10, 10)); //생성 - 벡터와 동일하게 데이터 추가
	list2.emplace_back(20, 20); //객체를 직접 생성해서 뒤에 넣을 수 있음
	list2.emplace_back(20, 20);
	list2.emplace_back(20, 20);
	list2.push_front(CMyPoint(30, 30)); //앞에 데이터 추가
	list2.unique(); //== 연산자 정의x ->오류
	//printArr(list2);
	cout << "===" << endl;

	//list 이어붙이는 작업
	list<CMyPoint> list3;
	list3.push_back(CMyPoint(40, 40));
	list3.push_back(CMyPoint(50, 50));
	list2.splice(list2.end(), list3); //list2의 끝에 list3를 이어붙임 -> list3는 비워짐
	cout << list3.size() << endl;
	//printArr(list2);

	list<string> std1({ "greenjoa1", "greenjoa2", "greenjoa3" });
	list<string> std2({ "bluejoa1", "bluejoa2"});
	list<string> std3({ "redjoa1" });

	vector<list<string>> std;
	std.push_back(std1);
	std.push_back(std2);
	std.push_back(std3);

	vector<string> stdname; //벡터 선언
	for (auto s : std) { //std에 있는거 하나씩 읽음
		for (auto t : s) {
			stdname.push_back(t);
		}
	}
	printArr(stdname);//->printArr vector로 바꿔야함

	//list<int> list1({ 1, 2, 3,3,3,4,5 });
	//list1.unique(); //중복되는 것 삭제
	//printArr(list1);
}