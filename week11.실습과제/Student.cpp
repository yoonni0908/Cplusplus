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

bool Student::operator==(const char* nameliteral)
{
	if (name == nameliteral) {
		return true;
	}
	return false;
}

bool Student::operator==(Student& student)
{
	if (name == student.getName() && score == student.getScore()) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& out, Student& pt)
{
	out << pt.name << "," << pt.score << endl;
	return out;
}
