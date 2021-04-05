/** --------------------------- 
* @file		Student.h
* @author	Charlie Welsh
* @version	1.0
*
* CS260-01 - Assignment 1
*	Headers for the Student class (and its operator overloads).
*
* --------------------------- */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
	public:
		//constructor
		Student(const string name = "anonymous", char letterGrade = 'W');
	
		//operator overloads
		friend bool operator == (const Student& stu1, const Student& stu2);
		friend ostream& operator<< (ostream& stream, const Student& student);
	private:
		string name;
		char letterGrade;  
};

// --------------------------- 
Student::Student(const string name, char letterGrade) {
	this->name = name;
	this->letterGrade = letterGrade;
}

//operator overloads (provided because they aren’t covered in detail until CS202)
bool operator == (const Student& stu1, const Student& stu2) {
	if (stu1.name == stu2.name && stu1.letterGrade == stu2.letterGrade)
		return true;
	else
		return false;
}

ostream& operator << (ostream& stream, const Student& student) {
	stream << student.name;
	stream << " (" << student.letterGrade << ") ";
	return stream;
}

#endif