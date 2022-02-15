//Osama Sultan
//ALL VALUES HARDCODED
//TESTED MOST OF FUNCS
#include"linked_list.h"
#include"linked_list.cpp"
int main()
{
	LinkedList<int> list;
	//inserting elements to head of list
	list.insertAtHead(2);
	list.insertAtHead(3);
	list.insertAtHead(4);
	list.insertAtHead(5);
	//inserting elements to tail of list
	list.insertAtTail(6);
	list.insertAtTail(7);
	list.insertAtTail(8);
	list.insertAtTail(9);
	cout << "length of list: ";
	cout << list.getLength() << endl;
	cout << "\nLIST IS : ";
	list.printList();
	cout << "\n***Testing delete at head function***\n";
	list.deleteAtHead();
	cout << endl<< list.getLength() << endl;
	list.printList();
	cout << "\n***Testing delete at tail function***\n";
	list.deleteAtTail();
	cout << endl << list.getLength() << endl;
	list.printList();
	cout << "\n***Testing insert After function***\n";
	list.insertAfter(2,10);
	list.printList();
	cout << "\n***Testing insert Before function***\n";
	list.insertBefore(2, 10);
	list.printList();
	cout << "\n***Testing Delete After function***\n";
	list.deleteAfter(2);
	list.printList();
	Node<int>* s = list.search(3);
	cout << "\n***Testing Delete before function***\n";
	list.deleteBefore(2);
	list.printList();
}