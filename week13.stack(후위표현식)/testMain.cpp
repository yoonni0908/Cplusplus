#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main() {

	cout << "202014182 �ڻ���" << endl;
	cout << "���� ǥ���� : ";
	string str1; //string ��ü
	getline(cin, str1); //������ �����ϰ� �ִ� ���� �Է¹���

	stringstream s(str1); //string���κ��� ������ �о
	string temp; //������ �о�� ���� �ӽ������� ����

	stack<double> dstack; //double Ÿ���� stack ����
	double operand; //�о�� ���� ���� ����

	while (s >> temp) { //s�κ��� ������ �о
		if (temp == "+" || temp == "-" || temp == "*" || temp == "/") {
			double a = dstack.top(); //�ֻ����� �ִ� ������ ������
			dstack.pop(); //����

			double b = dstack.top();
			dstack.pop();

			if (temp == "+") {
				dstack.push(a + b); //������ ����� stack�� push
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
	
	cout << "���� ��� : ";
	cout << dstack.top() << endl;
	dstack.pop(); //�����ϸ� stack�� ���� �� ������

	return 0;
}