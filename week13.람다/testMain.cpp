#include <iostream>
#include <map>
#include <list>
#include "Student.h"
#include <functional>
using namespace std;
using namespace std::placeholders;

bool sortdesc(int a, int b) {
	return a > b;
}

bool removescore(int a) {
	return a < 40;
}

int main() {

	list<Student> stdlist;
	stdlist.push_back(Student("greenjoa1", "홍길동", 80));
	stdlist.push_back(Student("greenjoa2", "이길동", 90));
	stdlist.push_back(Student("greenjoa3", "엄길동", 60));
	stdlist.push_back(Student("greenjoa4", "최길동", 50));

	//stdlist.remove_if(bind(equal_to<>(), _1, Student("greenjoa3", "엄길동", 60)));
	//람다표현식
	stdlist.remove_if([](auto i) {return i == Student("greenjoa3", "엄길동", 60); });
	for (auto it = stdlist.begin(); it != stdlist.end(); it++) {
		cout << *it << endl;
	}
	 
	
	//list<int> mylist = { 50, 60, 10, 30, 40, 90 };
	////mylist.remove_if(removescore); //40보다 작은 값들은 삭제
	////mylist.remove_if(bind(less<>(), _1, 40)); //내장함수 사용 -> 값을 하나 바인딩해서 사용, 나머지 조건 40을 값으로 줌
	////less<>는 두개의 값을 비교하므로 bind()함수 이용해야함.
	//mylist.remove_if([](auto i) {return i < 40; }); //람다 표현식
	//for (auto it = mylist.begin(); it != mylist.end(); it++) {
	//	cout << *it << endl;
	//}


	
}