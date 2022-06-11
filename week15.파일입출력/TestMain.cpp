#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void changeNumberByID(const string& filename, int id, const string& newNumber) {
	fstream data(filename);
	if (data.fail()) {
		cerr << "파일 열기 실패" << endl;
		return;
	}
	while (!data.eof()) {
		int temp;
		data >> temp;
		if (data.fail()) {
			break;
		}
		if (temp == id) { //제대로 읽었을 경우
			data.seekp(data.tellg());
			data << " " << newNumber;
			break;
		}
	}
}

int main() {
	changeNumberByID("userlist.txt", 125, "010-1111-5555");
}
