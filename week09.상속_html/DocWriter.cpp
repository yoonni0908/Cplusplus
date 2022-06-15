#include "DocWriter.h"
#include <iostream>
#include <fstream>
using namespace std;

DocWriter::DocWriter()
	:DocWriter("noFileName", "noContent") //���� ������
{
}

DocWriter::~DocWriter()
{
	cout << "DocWriter �Ҹ���" << endl;
}

DocWriter::DocWriter(const string& fileName, const string& content)
	:fileName(fileName), content(content)
{
	cout << "DocWriter ������" << endl;
}

void DocWriter::setFileName(const string fileName)
{
	this->fileName = fileName;
}

void DocWriter::setContent(const string& content)
{
	this->content = content;
}

void DocWriter::write()
{
	ofstream fout(fileName);
	fout << "2000000 ȫ�浿" << endl;
	fout << content << endl;
}

DocWriter& DocWriter::operator<<(const string& str)
{
	content += str + "\n";
	return *this;
}

DocWriter& DocWriter::operator<<(const int& num)
{
	content += to_string(num) + "\n";
	return *this;
}

void DocWriter::readFile()
{
	ifstream fin(fileName);
	if (fin.is_open()) {
		while (!fin.fail()) {
			string str;
			getline(fin, str);
			cout << str << endl;
		}
	}
}

void DocWriter::readFile() const
{
	ifstream fin(fileName);
	if (fin.is_open()) {
		while (!fin.fail()) {
			string str;
			getline(fin, str);
			cout << str << endl;
		}
	}
}
