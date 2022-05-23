#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include "CMyPoint.h"
using namespace std;

template<typename T>
void printArr(vector<T>& v) { //���ڷ� ���� ����-���۷��� ����
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";//iterator�� ����Ű�� ���� ���
	}
	cout << endl;
}

int main() {

	list<CMyPoint> list2;
	list2.push_back(CMyPoint(10, 10)); //���� - ���Ϳ� �����ϰ� ������ �߰�
	list2.emplace_back(20, 20); //��ü�� ���� �����ؼ� �ڿ� ���� �� ����
	list2.emplace_back(20, 20);
	list2.emplace_back(20, 20);
	list2.push_front(CMyPoint(30, 30)); //�տ� ������ �߰�
	list2.unique(); //== ������ ����x ->����
	//printArr(list2);
	cout << "===" << endl;

	//list �̾���̴� �۾�
	list<CMyPoint> list3;
	list3.push_back(CMyPoint(40, 40));
	list3.push_back(CMyPoint(50, 50));
	list2.splice(list2.end(), list3); //list2�� ���� list3�� �̾���� -> list3�� �����
	cout << list3.size() << endl;
	//printArr(list2);

	list<string> std1({ "greenjoa1", "greenjoa2", "greenjoa3" });
	list<string> std2({ "bluejoa1", "bluejoa2"});
	list<string> std3({ "redjoa1" });

	vector<list<string>> std;
	std.push_back(std1);
	std.push_back(std2);
	std.push_back(std3);

	vector<string> stdname; //���� ����
	for (auto s : std) { //std�� �ִ°� �ϳ��� ����
		for (auto t : s) {
			stdname.push_back(t);
		}
	}
	printArr(stdname);//->printArr vector�� �ٲ����

	//list<int> list1({ 1, 2, 3,3,3,4,5 });
	//list1.unique(); //�ߺ��Ǵ� �� ����
	//printArr(list1);
}