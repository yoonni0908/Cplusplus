#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"
using namespace std;

int random() {
	return rand() % 100;
}

bool checkKim(const Student& std) {
	if (std.getName().find("��") != string::npos) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	vector<Student> std;
	std.push_back(Student("2001", "ȫ�浿", 80));
	std.push_back(Student("2004", "��浿", 70));
	std.push_back(Student("2003", "�ֱ浿", 90));
	std.push_back(Student("2002", "�̱浿", 100));
	std.push_back(Student("2005", "��浿", 60));
	std.push_back(Student("2007", "�ֱ���", 95));
	std.push_back(Student("2006", "��浿", 75));

	//vector<Student>::iterator it = find(std.begin(), std.end(), Student("2003", "�ֱ浿", 90));
	//vector<Student>::iterator it = find(std.begin(), std.end(), "�ֱ浿");
	
	vector<Student>::iterator it = remove_if(std.begin(), std.end(), [](const Student& s) {return s.getScore() >= 90; });
	std.erase(it, std.end());
	for_each(std.begin(), std.end(), [](const Student& i) {cout << i << endl; });

	//vector<Student>::iterator it = std.begin(); //std.begin() ���� it�� �ʱⰪ���� ��
	//while (true) {
	//	it = find_if(it, std.end(), [](const Student& s) {return s.getScore() >= 90; }); //��ü�� �Լ�ó�� ����� �� �ֵ��� �����ε�
	//	if (it != std.end()) {
	//		cout << distance(std.begin(), it) << "��° ������ : " << *it << endl;
	//		it++;
	//	}
	//	else {
	//		//cout << "����" << endl;
	//		break;
	//	}
	//}
	//sort(std.begin(), std.end(), greater<Student>()); //operator < ȣ���.(��������)
	//greater<> Ÿ�� �����ϸ� ������ ������ - Ÿ�Ը�����ִ°� ����

	//sort(std.begin(), std.end(), [](const Student& left, const Student& right) { //sort()�� ID�� �������� ����
	//	return left.getId() > right.getId();
	//	});

	//for_each(std.begin(), std.end(), [](const Student& i) {cout << i << endl; });

	//vector<int> vec(10);
	////generate(vec.begin(), vec.end(), random);
	//generate(vec.begin(), vec.end(), [] {return rand() % 100; }); //generate()�Լ� ���
	////sort(vec.begin(), vec.end(), greater<int>()); //���� ���� ����

	//vector<int> vec2(5);
	//generate(vec2.begin(), vec2.end(), [] {return rand() % 50;  });
	//cout << vec.size() << "," << vec2.size() << endl; //ũ������
	//cout << vec.data() << "," << vec2.data() << endl; //��ġ����
	//vec.swap(vec2);
	//cout << vec.size() << "," << vec2.size() << endl;
	//cout << vec.data() << "," << vec2.data() << endl; //��ġ ���� �Ҵ� �ϴ°��� �ƴ� �ΰ� �ּҸ� �ٲ�

	//for_each(vec.begin(), vec.end(), [](const int i) {cout << i << endl; }); //���� �Լ� ���

}