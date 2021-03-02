/** --------------------------- 
* @file		LinkedListDemo.cpp
* @author	Charlie Welsh
* @version	1.0
*
* CS162-01 - Assignment 4.1
*	Implements a linked list.
*
* --------------------------- */

#include <iostream>
#include <fstream>
#include <iterator>
#include "LinkedList.cpp"

int main() {

	LinkedList ll = LinkedList();


	std::ifstream file("linkListTest.txt");

	std::string str;
	char i;
	
	while(file >> i) {
		switch (i) {
			case 'a':
				file >> str;
				if (ll.insert(str)) {
					std::cout << "Added " << str << std::endl;
				} else {
					std::cout << str << " cannot be added again" << std::endl;
				}
				break;
			case 'r':
				file >> str;
				if (ll.remove(str)) {
					std::cout << "Removing " << str << std::endl;
				} else {
					std::cout << "Couldn't remove " << str << std::endl;
				}
				break;
			case 'f':
				file >> str;
				if (ll.find(str) != 0) {
					std::cout << str << " is at position " << ll.find(str) << std::endl;
				} else {
					std::cout << str << " is not in the list" << std::endl;
				}
				break;
			case 'P':
				if (ll.count() == 1) {
					std::cout << "List contains " << ll.count() << " name: ";
				} else {
					std::cout << "List contains " << ll.count() << " names: ";
				}
				ll.print();
				break;
			case 'R':
				ll.removeAll();
				std::cout << "Removing all entries" << std::endl;
				break;
			default:
				file >> str;
				std::cout << "Not available" << std::endl;
		}
	}
}
