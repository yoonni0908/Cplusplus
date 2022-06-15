#pragma once
#include <string>
using std::string;
class DocWriter
{
protected:
	string fileName;
	string content;
public:
	DocWriter();
	~DocWriter();
	DocWriter(const string& fileName, const string& content);
	void setFileName(const string fileName);
	void setContent(const string& content);
	void write();
	DocWriter& operator<<(const string& str);
	DocWriter& operator<<(const int& num);
	void readFile(); //파일 읽고 출력하는 기능
	void readFile() const;
};

