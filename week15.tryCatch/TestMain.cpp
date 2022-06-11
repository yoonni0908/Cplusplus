#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <map> //map구조에 넣어놓고 찾는것
using namespace std;
int main() {

	ifstream dicfile("words.txt");
	map<string, string> dic; //key - string타입, data - string 타입
	//try..catch 문
	try {
		//if (!dicfile.fail()) {
		dicfile.exceptions(ifstream::failbit); //if문없이 예외사항 처리
			while (!dicfile.eof()) {
				string eng, kor;
				getline(dicfile, eng); //한 줄 읽어냄
				getline(dicfile, kor);
				dic.insert({ eng, kor }); //map data에 insert
			}
			auto it = dic.find("consider"); //find()함수
			if (it != dic.end()) { //존재할경우
				cout << it->first << " : " << it->second << endl; //fisrt는 key, second는 value
			}
			else {
				cout << "단어 없음" << endl;
			}
		//}
		//else {
		//	//cerr << "파일이 존재하지 않음" << endl;
		//	throw exception("파일이 존재하지 않음"); //예외사항 exception으로 처리
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