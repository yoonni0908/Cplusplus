#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Student.h"
using namespace std;
list<Student> getStudent(const list<list<Student>>&std, list<Student>droplist) //읽기 전용
{
	list<Student> stdname;
	for (auto l : std) { //auto&(x) -> const가 있어서 읽기전용인데 레퍼런스를 붙이면 수정이 되므로 레퍼런스를 붙이면 안됨
		l.sort();
		stdname.merge(l);
		stdname.unique(); //중복된 데이터 제거 
	}
	for (auto dropname : droplist) { //droplist에 있는 내용들 하나씩 가져와서 remove시켜줌
		stdname.remove(dropname);
	}
	return stdname;
}

void printArr(list<Student>& students) {
	for (auto& std : students) {
		cout << std << endl;
	}
}
//const로 받는다고 하면 const함수 호출 

int main() {
	cout << "202014182 박상윤" << endl;

	/*list<list<string>> std = { {"greenjoa1", "greenjoa2", "greenjoa3"},
	{"greenjoa4", "greenjoa2"} };
	std.push_back({ "bluejoa1", "greenjoa3" });
	list<string> droplist({ "bluejoa2", "greenjoa3" });

	auto students = getStudent(std, droplist);
	printArr(students);*/

	list<list<Student>> std = { { Student("greenjoa1", 10), Student("greenjoa2", 20)},
	{ Student("greenjoa3", 30), Student("greenjoa4", 40)} };
	std.push_back({ Student("bluejoa1", 10), Student("bluejoa2", 20) });
	list<Student> droplist({ Student("bluejoa1", 10), Student("bluejoa2", 20) });
	
	auto students = getStudent(std, droplist);
	printArr(students);

	return 0;
}