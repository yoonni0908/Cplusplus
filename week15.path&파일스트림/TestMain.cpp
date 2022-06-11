#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
using namespace std::filesystem;

void changeNumberByID(const string& filename, int id, const string& newNumber) {
	fstream data(filename);
	if (data.fail()) {
		cerr << "���� ���� ����" << endl;
		return;
	}
	while (!data.eof()) {
		int temp;
		data >> temp;
		if (data.fail()) {
			break;
		}
		if (temp == id) { //����� �о��� ���
			data.seekp(data.tellg());
			data << " " << newNumber;
			break;
		}
	}
}

int main() {
	//changeNumberByID("userlist.txt", 125, "010-1111-5555");
	//path p1("c:\\"); //���ϰ��
	//p1.append("users");
	//p1.append("greenjoa");
	//p1 /= "test.txt";
	//cout << p1 << endl;
	//for (auto& c : p1) {
	//	cout << c << endl;
	//}

	//directory_entry file(p1); //���� ���� ���
	//if (file.exists() && file.is_regular_file()) { //is_refgular_file->������������
	//	cout << file.file_size() << endl; //���� ������
	//}
	//else {
	//	cout << "������ �������� ����" << endl;
	//}
	path p1("c:/users/greenjoa");
	auto begin = recursive_directory_iterator(p1);
	auto end = recursive_directory_iterator();
	for (auto it = begin; it != end; it) {
		string spacer(it.depth() * 2, ' '); //��ĭ�� ����ó��
		auto& entry = *it;
		if (is_regular_file(entry)) {
			cout << spacer << "File : " << entry.path();
			cout << "(" << file_size(entry) << "byte)" << endl;
		}
		else if (is_directory(entry)) {
			cout << spacer << "Directory : " << entry.path() << endl;
		}
	}
}
