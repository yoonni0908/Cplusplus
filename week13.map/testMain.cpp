#include <iostream>
#include <map>
#include "Student.h"
using namespace std;
int main() {

	cout << "-----------cppclassA---------------" << endl;

	map<string, Student> cppclassA; //map ��ü ���� string(key�� �ش��ϴ� Ÿ��), Student(value)
	cppclassA["greenjoa1"] = Student("greenjoa1", "ȫ�浿", 60); //�迭 ������ ��� - ������ ����
	cppclassA.insert({ "greenjoa2", Student("greenjoa2", "��浿", 70) }); // insert() - ������ ����
	cppclassA.insert({ "greenjoa3", Student("greenjoa3", "�̱浿", 80) });
	cppclassA.emplace("greenjoa4", Student("greenjoa4", "�ֱ浿", 90)); //pair ��ü �����ؼ� ����

	for (const auto& p : cppclassA) { //cppclassA�� �ִ� ���Ҹ� �ϳ��� �޾Ƽ� ���
		cout << p.first << " : " << p.second << endl; //key�� ���ؼ� �ڵ����� ���ĵǼ� ���
	}
	//�Էµ� ������ �����Ϸ��� map���� ����x

	//find() -> ������ ã��
	auto pos = cppclassA.find("greenjoa3");
	if (pos != cppclassA.end()) {
		//cout << *pos << endl;
		cout << pos->first << " : " << pos->second << endl;
	}
	
	cout << "-----------cppclassB---------------" << endl;

	map<string, Student> cppclassB; 
	cppclassB.insert({ "greenjoa5", Student("greenjoa5", "�ڱ浿", 77) }); 
	cppclassB.insert({ "greenjoa6", Student("greenjoa6", "��浿", 85) });
	cppclassB.emplace("greenjoa3", Student("greenjoa3", "�̱浿", 80)); 

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

	//��� �����ϴ� ���
	auto node = cppclassA.extract("greenjoa1"); //cppclassA�κ��� ����
	cout << node.key() << ", " << node.mapped() << endl; // node.key()->����� Ű����, node.mapped()->����� value ����
	cppclassB.insert(move(node)); //r-value��ü�� �̵��Ǽ� classB�� insert�ǰ� classA������ ���ŵ�

	cout << "-----------cppclassA---------------" << endl;
	for (const auto& p : cppclassA) {
		cout << p.first << " : " << p.second << endl;
	}

	cout << "-----------cppclassB---------------" << endl;
	for (const auto& [key, value] : cppclassB) { //������ ���ε�
		cout << key << " : " << value << endl;
	}
}