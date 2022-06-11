#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <map> //map구조에 넣어놓고 찾는것
using namespace std;
int main() {

	int a; 
	cin.exceptions(ifstream::failbit);
	while (true) {
		try {
			cin >> a;
			/*if (cin.fail()) {
				throw exception("잘못된 값 입력");
			}*/
			cout << a << endl;
		}
		catch (exception e) {
			cerr << e.what() << endl;
			cin.clear(); //예외가 발생했을때 지우는 함수(초기화)
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //버퍼 지우는 작업
		}
	}
}