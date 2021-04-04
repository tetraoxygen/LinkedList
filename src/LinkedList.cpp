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

// --------------------------- 
template<class T> LinkedList<T>::LinkedList() {
	head = nullptr;
};

// --------------------------- 
template<class T> LinkedList<T>::~LinkedList() {
	removeAll();
}

// --------------------------- 
template <class T> void LinkedList<T>::print() {
	std::string elementDescriptor;
	int elementCount = this->count();
	
	if (elementCount == 1) {
		elementDescriptor = " element:\n";
	} else {
		elementDescriptor = " elements:\n";
	}
	
	std::cout << "The list contains the following " << this->count() << elementDescriptor << std::endl;
	
	Node<T>* current = head;
	
	while (current != nullptr) {
		std::cout << current->data;
		
		if (current->next != nullptr) {
			std::cout << ", ";
		}
		
		current = current->next;
	}
}

// --------------------------- 
template <class T> int LinkedList<T>::count() {
	int count = 0;
	Node<T>* current = head;
	while (current != nullptr) {
		count = count += 1;
		
		current = current->next;
	}
	return count;
}

// --------------------------- 
template <class T> bool LinkedList<T>::insert(T& data) {
	bool hasAddedItem = false;
	Node<T>* current = head;
	Node<T>* previous = nullptr;
	
	// Handle the first element in the list
	if (head == nullptr) {
		head = new Node<T> { .data = data, .next = nullptr };
		return true;
	}
	
	while (current != nullptr) {
		// If the strings are identical
		if (data == current->data) {
			return false;
		}
		
		if (data.compare(current->data) < 0) {
			if (previous) {
				previous->next = new Node<T> { .data = data, .next = current };
			} else {
				head = new Node<T> { .data = data, .next = current };
			}
			return true;
		}
		previous = current;
		current = current->next;
	}

	previous->next = new Node<T> { .data = data, .next = nullptr };

	return true;
}

// --------------------------- 
template <class T> bool LinkedList<T>::remove(T& data) {
	Node<T>* current = head;
	Node<T>* previous = nullptr;
	while (current != nullptr) {
		Node<T>* next = current->next;
		if (data == current->data) {
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
template <class T> int LinkedList<T>::find(T& data) {
	int count = 0;
	Node<T>* current = head;
	while (current != nullptr) {
		count = count += 1;
		
		if (data == current->data) {
			return count;
		}
			
		current = current->next;
	}
	return 0;
}

// --------------------------- 
template <class T> void LinkedList<T>::removeAll() {
	Node<T>* current = head;
	while (current != nullptr) {
		Node<T>* next = current->next;
		delete current;
		if (!current->next) {
			head = nullptr;
		}
		
		current = next;
	}
}