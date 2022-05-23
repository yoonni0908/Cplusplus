#include "Student.h"

Student::Student()
	:Student("Info", 0.0)
{
}

Student::~Student()
{
}

Student::Student(const string& name, const int& score)
	:name(name), score(score)
{
}

string Student::getName() const
{
	return name;
}

int Student::getScore() const
{
	return score;
}

bool Student::operator==(const string& s)
{
	return this->name == s;
}

bool Student::operator==(const Student& s)
{
	return (this->name == s.name && this->score == s.score);
}

bool Student::operator==(const Student& s) const
{
	return (this->name == s.name && this->score == s.score);
}

bool Student::operator<(const Student& s)
{
	return this->name < s.name;
}

ostream& operator<<(ostream& out, const Student& s)
{
	out << s.getName() << "," << s.getScore();
	return out;
}
