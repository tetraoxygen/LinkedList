/** --------------------------- 
* @file		LinkedList.h
* @author	Charlie Welsh
* @version	1.0
*
* CS162-01 - Assignment 4.2
*	Headers for the LinkedList class and its methods, as well as the Node<int> struct.
*
* --------------------------- */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>

template <class T> struct Node {
	T data;
	Node* next;
};

template <class T> class LinkedList {
	public: 
		/**
		*	Initializes a LinkedList with the head set to a Node<int> object 
		*/
		LinkedList();
		
		/**
		*	Destructor for LinkedList; it deletes all the Node<int>()s in the list. 
		*/
		~LinkedList();
		
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
		bool insert(T& data);
		
		/**
		*	Removes a string from the list. 
		*		@param str - the string to remove
		*		@return true if the item can be removed, false if it can't.
		*/
		bool remove(T& data);
		
		/**
		*	Finds a string's position in the list.
		*		@param str - the string to find
		*		@return the string's position in the list, 0 if the item can't be found.
		*/
		int find(T& data);
		
		/**
		*	Removes all elements in the list.
		*/
		void removeAll();
		
	private:
		Node<T>* head;
};

#endif