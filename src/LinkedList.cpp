#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
	head = nullptr;
};

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

int LinkedList::count() {
	int count = 0;
	Node* current = head;
	while (current != nullptr) {
		count = count += 1;
		
		current = current->next;
	}
	return count;
}

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