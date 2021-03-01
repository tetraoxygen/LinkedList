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
#include "LinkedList.cpp"

int main() {
	LinkedList ll = LinkedList();
	ll.print();
	
	std::string test = "test";
	std::string aardvark = "aardvark";
	
	std::string charlie = "charlie";
	std::string sarah = "sarah";
	
	std::string zebra = "zebra";

	std::string asdfadsf = "aaaaaaa";
	
	ll.insert(aardvark);
	ll.print();
	
	ll.insert(test);
	ll.print();
	
	ll.insert(asdfadsf);
	ll.print();
	
	ll.insert(charlie);
	ll.print();
	
	ll.insert(sarah);
	ll.print();
	
	ll.insert(zebra);
	ll.print();
}
