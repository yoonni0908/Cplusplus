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



//template<typename T>
//void printArr(T* arr, size_t N) {
//	for (int i = 0; i < N; i++) {
//		cout << arr[i] << endl;
//	}
//	cout << endl;
//
//}
//
//template<>
//void printArr(char* arr, size_t N) { //문자 배열이 들어왔을 때 예외적으로 처리
//	cout << arr << endl; //null값 만날때까지 출력
//}
//
//template<typename T, size_t N> //사이즈 정보 상속값이 들어옴, 사이즈도 추론
//void showArr(T(&arr)[N]) { //배열정보를 받을 수 있음
//	for (auto i : arr) {
//		cout << i << endl;
//	}
//	cout << endl;
//}
//
//template<typename T, size_t N> 
//void sortDesc(T(&arr)[N]) { 
//	for (size_t i = 0; i < N - 1; i++) {
//		for (size_t j = i + 1; j < N; j++) {
//			if (arr[i] < arr[j]) {
//				T temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
//}
//
//template<typename T, size_t N>
//void sortAsc(T(&arr)[N]) {
//	for (size_t i = 0; i < N - 1; i++) {
//		for (size_t j = i + 1; j < N; j++) {
//			if (arr[i] > arr[j]) {
//				T temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
//}

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
	
	//Stack<> stack;
	//stack.push(10);

	//Stack<int, 40> istack;
	//istack.push(10);
	//istack.push(20);
	//istack.push(30);
	//istack.push(40);
	//istack.push(50);
	//int item;
	//while (istack.pop(item)) { //LAST IN FIRST OUT
	//	cout << item << endl;
	//}

	//Stack<double> dstack;
	//dstack.push(10.0);
	//dstack.push(20.0);
	//dstack.push(30.0);
	//dstack.push(40.0);
	//dstack.push(50.0);
	//double ditem;
	//while (dstack.pop(ditem)) { //LAST IN FIRST OUT
	//	cout << ditem << endl;
	//}

	//Stack<string> sstack;
	//sstack.push("greenjoa1");
	//sstack.push("greenjoa2");
	//sstack.push("greenjoa3");
	//string sitem;
	//while (sstack.pop(sitem)) { //LAST IN FIRST OUT
	//	cout << sitem << endl;
	//}

	//Stack<CMyPoint> pstack;
	//pstack.push(CMyPoint(10, 20));
	//pstack.push(CMyPoint(10, 20));
	//pstack.push(CMyPoint(10, 20));
	//CMyPoint ptitem;
	//while (pstack.pop(ptitem)) { //LAST IN FIRST OUT
	//	cout << ptitem << endl;
	//}
	//CMyPoint arr[]{ CMyPoint(20, 30), CMyPoint(10, 20), CMyPoint(40,50) };
	//sortDesc(arr);
	//sortAsc(arr);
	//showArr(arr);
	
	/*int arr1[]{ 1, 2, 3, 4, 5 };
	double arr2[]{ 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	string arr3[]{ "greenjoa1", "greenjoa2", "greenjoa3" };
	sortDesc(arr1);
	showArr(arr1);
	sortDesc(arr2);
	showArr(arr2);
	sortDesc(arr3);
	showArr(arr3);*/


	//char arr4[]{'a','b',0 };

	//showArr(arr1);
	//showArr(arr2);

	/*printArr<int>(arr1, size(arr1));
	printArr(arr2, size(arr2));
	printArr(arr3, size(arr3));
	printArr(arr4, size(arr4));*/
}
