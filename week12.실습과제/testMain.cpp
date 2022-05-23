#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Student.h"
using namespace std;
list<Student> getStudent(const list<list<Student>>&std, list<Student>droplist) //�б� ����
{
	list<Student> stdname;
	for (auto l : std) { //auto&(x) -> const�� �־ �б������ε� ���۷����� ���̸� ������ �ǹǷ� ���۷����� ���̸� �ȵ�
		l.sort();
		stdname.merge(l);
		stdname.unique(); //�ߺ��� ������ ���� 
	}
	for (auto dropname : droplist) { //droplist�� �ִ� ����� �ϳ��� �����ͼ� remove������
		stdname.remove(dropname);
	}
	return stdname;
}

void printArr(list<Student>& students) {
	for (auto& std : students) {
		cout << std << endl;
	}
}
//const�� �޴´ٰ� �ϸ� const�Լ� ȣ�� 

int main() {
	cout << "202014182 �ڻ���" << endl;

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