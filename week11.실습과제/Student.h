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
	friend ostream& operator<<(ostream& out, Student& pt);
	bool operator==(const char* nameliteral);
	bool operator==(Student& student);
};

