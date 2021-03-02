/** --------------------------- 
* @file		LinkedList.cpp
* @author	Charlie Welsh
* @version	1.0
*
* CS162-01 - Assignment 4.2
*	Implements the LinkedList class.
*
* --------------------------- */

#include "LinkedList.h"
#include <iostream>

// --------------------------- 
LinkedList::LinkedList() {
	head = nullptr;
};

// --------------------------- 
LinkedList::~LinkedList() {
	removeAll();
}

// --------------------------- 
void LinkedList::print() {
	Node* current = head;
	while (current != nullptr) {
		std::cout << current->data;
		
		if (current->next != nullptr) {
			std::cout << ", ";
		}
		
		current = current->next;
	}
	std::cout << std::endl;
}

// --------------------------- 
int LinkedList::count() {
	int count = 0;
	Node* current = head;
	while (current != nullptr) {
		count = count += 1;
		
		current = current->next;
	}
	return count;
}

// --------------------------- 
bool LinkedList::insert(std::string str) {
	bool hasAddedItem = false;
	Node* current = head;
	Node* previous = nullptr;
	
	// Handle the first element in the list
	if (head == nullptr) {
		head = new Node { .data = str, .next = nullptr };
		return true;
	}
	
	while (current != nullptr) {
		// If the strings are identical
		
		if (str.compare(current->data) == 0) {
			return false;
		}
		
		if (str.compare(current->data) < 0) {
			if (previous) {
				previous->next = new Node { .data = str, .next = current };
			} else {
				head = new Node { .data = str, .next = current };
			}
			return true;
		}
		previous = current;
		current = current->next;
	}

	previous->next = new Node { .data = str, .next = nullptr };

	return true;
}

// --------------------------- 
bool LinkedList::remove(std::string str) {
	Node* current = head;
	Node* previous = nullptr;
	while (current != nullptr) {
		Node* next = current->next;
		if (str.compare(current->data) == 0) {
			if (previous) {
				previous->next = next;
			} else {
				head = next;
			}
			delete current;
			return true;
		}
		
		previous = current;
		current = next;
	}
	return false;
}

// --------------------------- 
int LinkedList::find(std::string str) {
	int count = 0;
	Node* current = head;
	while (current != nullptr) {
		count = count += 1;
		
		if (str.compare(current->data) == 0) {
			return count;
		}
			
		current = current->next;
	}
	return 0;
}

// --------------------------- 
void LinkedList::removeAll() {
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		if (!current->next) {
			head = nullptr;
		}
		
		current = next;
	}
}