#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <map> //map������ �־���� ã�°�
using namespace std;
int main() {

	ifstream dicfile("words.txt");
	map<string, string> dic; //key - stringŸ��, data - string Ÿ��
	//try..catch ��
	try {
		//if (!dicfile.fail()) {
		dicfile.exceptions(ifstream::failbit); //if������ ���ܻ��� ó��
			while (!dicfile.eof()) {
				string eng, kor;
				getline(dicfile, eng); //�� �� �о
				getline(dicfile, kor);
				dic.insert({ eng, kor }); //map data�� insert
			}
			auto it = dic.find("consider"); //find()�Լ�
			if (it != dic.end()) { //�����Ұ��
				cout << it->first << " : " << it->second << endl; //fisrt�� key, second�� value
			}
			else {
				cout << "�ܾ� ����" << endl;
			}
		//}
		//else {
		//	//cerr << "������ �������� ����" << endl;
		//	throw exception("������ �������� ����"); //���ܻ��� exception���� ó��
		//}
	}
	catch (exception e) {
		cerr << e.what() << endl;
		cerr << dicfile.fail() << endl;
		cerr << dicfile.good() << endl;
		cerr << dicfile.bad() << endl;
		cerr << dicfile.eof() << endl;
	}
}