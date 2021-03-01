#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

struct Node {
	std::string data;
	Node* next;
};

class LinkedList {
	public: 
		/**
		*	Initializes a LinkedList with the head set to a Node object 
		*/
		LinkedList();
		
		
		/**
		*	Prints the value of all members of the list on one line.
		*/
		void print();
		
		/**
		*	Returns the number of members in the list.
		*		@return the number of members in the list
		*/
		int count();
		
		/**
		*	Inserts a new string in the list in alphabetical order. Duplicates are disallowed.
		*		@param str - the string to insert
		*		@return true if the item can be inserted, false if it can't.
		*/
		bool insert(std::string str);
	private:
		Node* head;
};

#endif