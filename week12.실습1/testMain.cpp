#include <iostream>
#include <string>
#include <vector>
#include "CMyPoint.h"
using namespace std;

template<typename T>
void printArr(vector<T>& v) { //���ڷ� ���� ����-���۷��� ����
	for (auto it = v.begin(); it!= v.end(); it++) {
		cout << *it << endl; //iterator�� ����Ű�� ���� ���
	}
	cout << endl;
}

int main() {

	vector<unique_ptr<CMyPoint>> arr;
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));
	arr.push_back(make_unique<CMyPoint>(10, 10));

	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << **it << ""; 
	}

	//vector<CMyPoint*> arr; //������ �ּҰ��� ����
	//arr.push_back(new CMyPoint(10, 10));
	//arr.push_back(new CMyPoint(10, 10));
	//arr.push_back(new CMyPoint(10, 10));
	//for (auto it = arr.begin(); it != arr.end(); it++) {
	//	cout << **it << ""; //�ּҰ��� ����Ű�� ���� ���
	//	delete* it; //iterator�� ����Ű�� ��(�ּҰ�) ����
	//}

	
	//���� ���� ������ ���Ϳ� ����
	//vector<CMyPoint> arr;
	//for (int i = 0; i < 5; i++) {
	//	//arr.push_back(CMyPoint(i * 10, i * 10)); //r-value ��ü
	//	arr.emplace_back(i * 10, i * 10); //������ ��ü ȣ��
	//	cout << endl << endl;
	//}
	
	
	
	//vector<CMyPoint> arr3(&arr[0], &arr[3]); //��������
	//printArr(arr3);
	

	//vector<int> intarr1(10); //�� 10���� ���� ����
	//cout << intarr1.size() << endl; //10
	//cout << intarr1.capacity() << endl; //10

	//�����Ҵ�
	//vector<int> intarr1;
	//for (int i = 0; i < 10; i++) {
	//	intarr1.push_back(i);
	//	cout << intarr1.size() << endl;
	//	cout << intarr1.capacity() << endl; //���� �̸� Ȯ���ϴ� ����
	//	cout << intarr1.data() << endl; //�ּҰ� 
	//	cout << endl;
	//}

	//���Ϳ� ������ ����
	//vector<int> arr1({ 1, 2, 3,4, 5 }); //�迭 �ʱ�ȭ

	//vector<double> arr2;
	//arr2.push_back(10.5); //������ ����
	//arr2.push_back(10.5);
	//arr2.push_back(10.5);
	//arr2.insert(arr2.begin(), 2.5); //������ ������ �־����

	//printArr(arr1);
	//cout << "===============" << endl;
	//printArr(arr2);
}