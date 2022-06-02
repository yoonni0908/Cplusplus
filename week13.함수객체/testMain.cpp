#include <iostream>
#include <map>
#include "Student.h"
using namespace std;

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int calculate(int a, int b, int(*func)(int, int)) { //���ڷ� �Լ� �̸��� ���� , �Լ� �̸��� �����ͷ� ����
	return func(a, b);
}

template<typenmae T>
auto calculate(int a, int b, T func) {
	return func(a, b);
}

//auto calculate(int a, int b, minus<int> func) {
//	return func(a, b);
//}

bool sortdesc(int a, int b) {
	return a > b;
}

int main() {

	list<Student> stdlist;
	stdlist.push_back(Student("greenjoa1", "ȫ�浿", 80));
	stdlist.push_back(Student("greenjoa2", "�̱浿", 90));
	stdlist.push_back(Student("greenjoa3", "���浿", 60));
	stdlist.push_back(Student("greenjoa4", "�ֱ浿", 50));
	stdlist.sort(greater<>()); //����- ��������(����Ʈ)����, greater

	for (auto it = stdlist.begin(); it != stdlist.end(); it++) {
		cout << *it << endl;
	}
	 
	//list<int> mylist = { 50, 60, 10, 30, 40, 90 };
	//mylist.remove_if(removescore)
	////mylist.sort(greater<>());  //sortdesc() ���ص� �����Լ��� �������� ����
	//for (auto it = mylist.begin(); it != mylist.end(); it++) {
	//	cout << *it << endl;
	//}


	/*plus<int> p1;
	minus<int> m1;

	cout << calculate(10, 20, add) << endl;
	cout << calculate(10, 20, sub) << endl;*/

	
}