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
	std::cout << i << std::endl;
		switch (i) {
			case 'a':
				file >> str;
				if (ll.insert(str)) {
					std::cout << "Added " << str << std::endl;
				} else {
					std::cout << str << " cannot be added again" << std::endl;
				}
				break;
			case 'P':
				std::cout << "List Contains " << ll.count() << " names: ";
				ll.print();
				break;
			default:
				std::cout << "Not available" << std::endl;
		}
	}
}
