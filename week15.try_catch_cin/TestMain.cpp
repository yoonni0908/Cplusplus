#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <map> //map������ �־���� ã�°�
using namespace std;
int main() {

	int a; 
	cin.exceptions(ifstream::failbit);
	while (true) {
		try {
			cin >> a;
			/*if (cin.fail()) {
				throw exception("�߸��� �� �Է�");
			}*/
			cout << a << endl;
		}
		catch (exception e) {
			cerr << e.what() << endl;
			cin.clear(); //���ܰ� �߻������� ����� �Լ�(�ʱ�ȭ)
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //���� ����� �۾�
		}
	}
}