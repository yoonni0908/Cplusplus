#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student
{
private:
	string name;
	int score;
public:
	Student();
	~Student();
	Student(const string& name, const int& score);
	string getName() const;
	int getScore() const;
	friend ostream& operator<<(ostream& out, const Student& s);
	bool operator==(const string& s);
	bool operator==(const Student& s);
	bool operator==(const Student& s) const; //const 멤버함수는 오버로딩 대상
	bool operator<(const Student& s);
	//bool operator<(const Student& s) const;
};



