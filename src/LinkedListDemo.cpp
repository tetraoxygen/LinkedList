/** --------------------------- 
* @file		LinkedListDemo.cpp
* @author	Charlie Welsh
* @version	1.0
*
* CS260-01 - Assignment 1
*	Demonstrates a linked list.
*
* --------------------------- */

#include "LinkedList.cpp"
#include "Student.h"

using namespace std;

int main() {

	// test template with ints --------------------------------
	LinkedList<int> intList; 
	intList.prepend(10);
	intList.prepend(20);
	intList.prepend(5);
	intList.append(15);
	intList.append(25);
	intList.print();

	cout << "5 is in position " << intList.find(5) << endl;
	cout << "15 is in position " << intList.find(15) << endl;
	cout << "20 is in position " << intList.find(20) << endl;
	cout << "8 is in position " << intList.find(8) << endl;

	intList.remove(15);
	intList.remove(5);
	intList.remove(25);
	intList.print();
	
	intList.removeAll();
	intList.print();
	cout << endl << endl;
	
	// test on list of chars --------------------------------
	LinkedList<char>* charList = new LinkedList<char>;
	charList->append('k');
	charList->append('s');
	charList->prepend('r');
	charList->prepend('o');
	charList->prepend('w');
	charList->print();

	charList->remove('r');
	charList->remove('w');
	charList->remove('s');
	charList->print();

	charList->removeAll();
	charList->print();
	delete charList;
	cout << endl << endl;

	// test it on Students ------------------------------------
	LinkedList<Student>* studentList = new LinkedList<Student>;
	studentList->append(Student("Bjarne", 'C'));
	studentList->append(Student("Bjarne", '+'));
	studentList->prepend(Student("Brian", 'C'));
	studentList->append(Student("Dennis", 'C'));
	studentList->print();
	cout << "Bjarne is in position " << studentList->find(Student("Bjarne", 'C')) << endl;
	cout << "Brian is in position " << studentList->find(Student("Brian", 'C')) << endl;
	cout << "Dennis is in position " << studentList->find(Student("Dennis", 'C')) << endl;
	
	studentList->remove(Student("Bjarne", 'C'));
	studentList->remove(Student("Brian", 'C'));
	studentList->remove(Student("Dennis", 'C'));
	studentList->print();
	
	studentList->removeAll();
	studentList->print();
	
	delete studentList;
	
	return 1;
}
