//Osama Sultan
#pragma once
#include<iostream>
using namespace std;
template <class type>
struct Node
{
	Node<type>* next;
	type data;
	Node(int inData, Node* nPtr = NULL)
	{
		data = inData;
		next = nPtr;
	}
};
template<class type>
class LinkedList
{
private:
	Node<type>* head;
	Node<type>* tail;
public:
	LinkedList();
	LinkedList(const Node<type>& cpy);
	~LinkedList();
	bool isEmpty();
	void insertAtHead(type val);
	void insertAtTail(type val);
	void deleteAtHead();
	void deleteAtTail();
	void printList();
	int getLength();
	Node<type>* getNode(int n);
	bool insertAfter(type key, type value);
	bool insertBefore(type key, type value);
	bool deleteAfter(type key);
	bool deleteBefore(type key);
	Node<type>* search(type key);
};