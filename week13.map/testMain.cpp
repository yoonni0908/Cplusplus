#include <iostream>
#include <map>
#include "Student.h"
using namespace std;
int main() {

	cout << "-----------cppclassA---------------" << endl;

	map<string, Student> cppclassA; //map 객체 생성 string(key에 해당하는 타입), Student(value)
	cppclassA["greenjoa1"] = Student("greenjoa1", "홍길동", 60); //배열 연산자 사용 - 데이터 삽입
	cppclassA.insert({ "greenjoa2", Student("greenjoa2", "김길동", 70) }); // insert() - 데이터 삽입
	cppclassA.insert({ "greenjoa3", Student("greenjoa3", "이길동", 80) });
	cppclassA.emplace("greenjoa4", Student("greenjoa4", "최길동", 90)); //pair 객체 생성해서 삽입

	for (const auto& p : cppclassA) { //cppclassA에 있는 원소를 하나씩 받아서 출력
		cout << p.first << " : " << p.second << endl; //key에 의해서 자동으로 정렬되서 출력
	}
	//입력된 순서를 유지하려면 map구조 적절x

	//find() -> 데이터 찾기
	auto pos = cppclassA.find("greenjoa3");
	if (pos != cppclassA.end()) {
		//cout << *pos << endl;
		cout << pos->first << " : " << pos->second << endl;
	}
	
	cout << "-----------cppclassB---------------" << endl;

	map<string, Student> cppclassB; 
	cppclassB.insert({ "greenjoa5", Student("greenjoa5", "박길동", 77) }); 
	cppclassB.insert({ "greenjoa6", Student("greenjoa6", "고길동", 85) });
	cppclassB.emplace("greenjoa3", Student("greenjoa3", "이길동", 80)); 

	for (const auto& p : cppclassB) { 
		cout << p.first << " : " << p.second << endl; 
	}

	cppclassA.merge(cppclassB);

	cout << "-----------cppclassA---------------" << endl;
	for (const auto& p : cppclassA) { 
		cout << p.first << " : " << p.second << endl;
	}

	cout << "-----------cppclassB---------------" << endl;
	for (const auto& p : cppclassB) { 
		cout << p.first << " : " << p.second << endl; 
	}

	//노드 추출하는 기능
	auto node = cppclassA.extract("greenjoa1"); //cppclassA로부터 추출
	cout << node.key() << ", " << node.mapped() << endl; // node.key()->노드의 키정보, node.mapped()->노드의 value 정보
	cppclassB.insert(move(node)); //r-value객체가 이동되서 classB에 insert되고 classA에서는 제거됨

	cout << "-----------cppclassA---------------" << endl;
	for (const auto& p : cppclassA) {
		cout << p.first << " : " << p.second << endl;
	}

	cout << "-----------cppclassB---------------" << endl;
	for (const auto& [key, value] : cppclassB) { //구조적 바인딩
		cout << key << " : " << value << endl;
	}
}