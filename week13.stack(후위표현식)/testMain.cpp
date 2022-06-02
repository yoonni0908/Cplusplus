#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main() {

	cout << "202014182 박상윤" << endl;
	cout << "후위 표현식 : ";
	string str1; //string 객체
	getline(cin, str1); //공백을 포함하고 있는 줄을 입력받음

	stringstream s(str1); //string으로부터 데이터 읽어냄
	string temp; //데이터 읽어내는 것을 임시적으로 저장

	stack<double> dstack; //double 타입의 stack 선언
	double operand; //읽어내기 위한 변수 선언

	while (s >> temp) { //s로부터 데이터 읽어냄
		if (temp == "+" || temp == "-" || temp == "*" || temp == "/") {
			double a = dstack.top(); //최상위에 있는 데이터 가져옴
			dstack.pop(); //삭제

			double b = dstack.top();
			dstack.pop();

			if (temp == "+") {
				dstack.push(a + b); //연산한 결과값 stack에 push
			}
			else if (temp == "-") {
				dstack.push(b - a);
			}
			else if (temp == "*") {
				dstack.push(a * b);
			}
			else if (temp == "/") {
				dstack.push(b / a);
			}
		}
		else {
			stringstream op(temp);
			op >> operand;
			dstack.push(operand);
		}
	}
	
	cout << "연산 결과 : ";
	cout << dstack.top() << endl;
	dstack.pop(); //삭제하면 stack에 내용 다 없어짐

	return 0;
}