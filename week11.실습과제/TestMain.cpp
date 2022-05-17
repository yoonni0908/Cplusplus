#include <iostream>
#include <string>
#include"ArrayData.h"
#include"CMyPoint.h"
#include "Student.h"
using namespace std;

//template<typename T>
//T search(T* arr, size_t N, T key) {
//	for (int i = 0; i < N; i++) {
//		if (arr[i] == key) {
//			return i;
//		}
//	}
//	return -1;
//}

template<typename T1, typename T2>
int search(T1* arr, size_t N, T2 key) {
	for (int i = 0; i < N; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}


int main() {

	cout << "202014182 ¹Ú»óÀ±" << endl;
	
	Student std[3] = { Student("greenjoa1", 70),Student("greenjoa2", 50),Student("greenjoa3", 80) };
	
	int idx3 = search(std, 3, "greenjoa2");
	if (idx3 != -1) {
		cout << std[idx3] << endl;
	}

	/*int idx3 = search(std, 3, Student("greenjoa3", 80));
	if (idx3 != -1) {
		cout << std[idx3] << endl;
	}*/
	
	
	//int arr[5] = { 5, 4, 3, 2, 1 };
	/*int idx1 = search(arr, 5, 3);
	if (idx1 != -1) {
		cout << arr[idx1] << endl;
	}*/

	//string id[3] = { "greenjoa1", "greenjoa2", "greenjoa3" };
	/*int idx2 = search(id, 3, "greenjoa2");
	if (idx2 != -1) {
		cout << id[idx2] << endl;
	}*/


	/*ArrayData<CMyPoint> arr1;
	arr1.addElement(CMyPoint(10, 20));
	arr1.addElement(CMyPoint(20, 20));
	arr1.addElement(CMyPoint(30, 20));
	cout << arr1 << endl;

	ArrayData<CMyPoint> arr2 = arr1;
	cout << arr2 << endl;

	ArrayData<CMyPoint> arr3 = move(arr2);
	cout << arr3 << endl;*/
}