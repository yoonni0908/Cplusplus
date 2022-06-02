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
	stdlist.push_back(Student("greenjoa1", "ȫ�浿", 80));
	stdlist.push_back(Student("greenjoa2", "�̱浿", 90));
	stdlist.push_back(Student("greenjoa3", "���浿", 60));
	stdlist.push_back(Student("greenjoa4", "�ֱ浿", 50));

	//stdlist.remove_if(bind(equal_to<>(), _1, Student("greenjoa3", "���浿", 60)));
	//����ǥ����
	stdlist.remove_if([](auto i) {return i == Student("greenjoa3", "���浿", 60); });
	for (auto it = stdlist.begin(); it != stdlist.end(); it++) {
		cout << *it << endl;
	}
	 
	
	//list<int> mylist = { 50, 60, 10, 30, 40, 90 };
	////mylist.remove_if(removescore); //40���� ���� ������ ����
	////mylist.remove_if(bind(less<>(), _1, 40)); //�����Լ� ��� -> ���� �ϳ� ���ε��ؼ� ���, ������ ���� 40�� ������ ��
	////less<>�� �ΰ��� ���� ���ϹǷ� bind()�Լ� �̿��ؾ���.
	//mylist.remove_if([](auto i) {return i < 40; }); //���� ǥ����
	//for (auto it = mylist.begin(); it != mylist.end(); it++) {
	//	cout << *it << endl;
	//}


	
}