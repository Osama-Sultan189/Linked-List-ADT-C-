//Osama Sultan
#include"linked_list.h"
template<class type>
LinkedList<type>::LinkedList()
{
	head = NULL;
	tail = NULL;
}
template<class type>
LinkedList<type>::LinkedList(const Node<type>& cpy)
{
	head = cpy->head;
	tail = cpy->tail;
	//coping head and tail of list so can access all list with these
}
template<class type>
LinkedList<type>::~LinkedList()
{
	Node<type>* temp = head;
	while (temp)
	{
		head = head->next;
		delete temp; //deleting all links
		temp = head;
	}
}
template<class type>
bool LinkedList<type>::isEmpty()
{
	return head == NULL; //if head is null then list is empty
}
template<class type>
void LinkedList<type>:: insertAtHead(type val)
{
	Node<type>* newNode = new Node<type>(val);
	if (isEmpty())
		head = tail = newNode;
	else
	{
		newNode->next = head;
		head = newNode;
	}

}
template<class type>
void LinkedList<type>::insertAtTail(type val)
{
	Node<type>* newNode = new Node<type>(val);
	if (isEmpty())
		tail = head = newNode;
	else
	{
		tail->next = newNode; //inserting elemnt at tail
		tail = newNode;
	}

}
template<class type>
void LinkedList<type>::deleteAtHead()
{
	if (!isEmpty())
	{
		Node<type>* temp = head;
		head = head->next;
		delete temp;
		if (isEmpty())
			tail = NULL;
	}
}
template<class type>
void LinkedList<type>::deleteAtTail()
{
	Node<type>* second_last = head;  // at the end this will be last
	Node<type>* last = second_last->next->next;  // this will be deleted
	while (last != NULL)
	{
		second_last = second_last->next;
		last = second_last->next->next;
	}
	delete second_last->next;
	second_last->next = NULL;
}
template<class type>
void LinkedList<type>::printList()
{
	Node<type>* temp = head;
	while (temp)
	{
		cout << temp->data << " --> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}
template<class type>
int LinkedList<type>::getLength()
{
	Node<type>* temp = head;
	int len=0;
	while (temp)
	{
		++len;//counting elements
		temp = temp->next;
	}
	return len;
}
template<class type>
Node<type>* LinkedList<type>::getNode(int n)
{
	Node<type>* temp = head;
	int len = 0;
	while (temp)
	{
		++len;
		if (len == n)
			break;
		temp = temp->next;
	}
	if (len <= this->getLength())
		return temp;
	else 
		return NULL;
}
template<class type>
bool LinkedList<type>::insertAfter(type key, type value)
{
	Node<type>* check = head;//after this
	Node<type>* nextToHead = head->next;//before this
	while (check != NULL)
	{
		nextToHead = nextToHead->next;
		check = check->next;
		if (check->data == key)
		{
			Node<type>* insert = new Node<type>(value);//inserting after key and before its next
			insert->next = nextToHead;
			check->next = insert;
			return true;
		}
	}
	return false;
}
template<class type>
bool LinkedList<type>::insertBefore(type key, type value)
{
	Node<type>* check = head; //from start
	Node<type>* nextElem = head->next; //next
	//elemnet will be inserted between these two
	while (nextElem != NULL )
	{
		check = nextElem;
		nextElem = nextElem->next;
		if (nextElem->data == key)
		{
			Node<type>* insert = new Node<type>(value);
			insert->next = nextElem;
			check->next = insert;
			return true;
		}
	}
	return false;
}
template<class type>
bool LinkedList<type>::deleteAfter(type key)
{
	Node<type>* temp = search(key);
	if (temp)
	{
		if (temp != tail) 
		{
			Node<type>* tmp = temp->next;
			if (temp->next != tail)        //move one time next with tail conditions
				temp->next = temp->next->next;
			else if (temp->next == tail)
			{
				tail = temp;
				temp->next = NULL;
			}
			delete tmp;          //deleting atempter element
			return true;
		}
	}
	else
		return false;
}
template<class type>
bool LinkedList<type>::deleteBefore(type key)
{
	Node<type>* temp = search(key);
	if (temp) 
	{
		temp = head;
		if (temp == head && temp->data == key)     //for 1st and second index
			return false;         //before head no element exists
		else if (temp->next->data == key) 
		{
			head = head->next;
			delete temp;       //delete node before elment
			return true;
		}
		else 
		{
			while (temp) 
			{
				if (temp->next->next->data == key) 
				{    //for remaining indexes
					Node<type>* tmp = temp->next;
					temp->next = temp->next->next;
					delete tmp;
					return true;
				}
				else
					temp = temp->next;
			}
		}
	}
	else
		return false;
}
template <class type>
Node<type> *LinkedList<type>::search(type key)
{
	Node<type>* temp = head;
	while (temp)
	{
		if (temp->data == key)
			return temp;
		else
			temp = temp->next;
	}
	return NULL;

}