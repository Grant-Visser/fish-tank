#ifndef NEW_H
#define NEW_H
#include<cstdlib>
#include<iostream>

template <typename T>
struct Node
{
	T datum;
	Node<T>* next;
}
template <typename T>
class Interator
{
	public:
		Iterator(Node<T>* node);
		Iterator<T> operator++();
		T& operator*();
		bool operator!=(Iterator<T> rhs);
	private:
		Node<T>* node;
}
template<typename T>
Iterator::Iterator(Node<T>* node)
{
	this->node = node;
}
template<typename T>
Iterator::Iterator<T> operator++()
{
	node = node->next;
	Iterator<T> ret(node);
	return ret;
}
template<typename T>
Iterator::T& operator*()//De-referencing something!
{
	return node->datum;
}
template<typename T>
bool Iterator::operator!=(Iterator<T> rhs)
{
	return node != rhs.node
}

template <typename T>
class List
{
public:
	List();//Constructor
	List(const List<T>& other);
	List<T>& operator=(const List<T>& rhs);
	
	void insertFirst(T Value);
	void insertAfter(T Value, Node<T>* before); //Not Complete! Many More alterations to be made!!!!
	void insertLast(T Value);
	Node<T>* Find(T Value);
	template <typename T1>
	friend ostream& operator<<(ostream& lhs, list<T1> rhs);
	int getSize()const;
	void clean();
	Iterator<T> begin();
	Iterator<T> end();
	
	~List();
private:
	void copy(List<T>& other);
	int size;
	Node<T>* head; //First Element in the list.
	Node<T* tail;
};
	
	using namespace std;

	//Imp

	template <typename T>
	List<T>List()//Constructor
	{
		size = 0;
		head = NULL;
		tail = NULL;
	}
	
	template <typename T>
	List<T>List(const List<T>& other)
	{
		copy(other);
	}
	
	template <typename T>
	List<T>& List<T>::operator=(const List<T>& rhs)
	{
		if (this != &rhs)
		{
				clean();
				copy(rhs);
		}
		return *this;
	}
	
	template <typename T>
	void List<T>::clean()
	{
		Node<T>* current = head;
		while (current != NULL)
		{
			Node<T>* Successor = current->next;
			delete current;
			current = next;
		}
		size = 0;
		head = NULL;
		tail= NULL;
	}
	
	template <typename T>
	void List<T>::copy(List<T>& other)
	{
		size = other.size;
		Node<T>* current = other.head;
		if (other.size == 0)
		{
			head = NULL;
			tail = NULL;
		}else
		{
			Node<T>* current = other.head;
			while (current != NULL)
			{
				insertLast(current->datum);
				//we could use current++ with arrays but we can't any more
				current = current->next;
			}
		}
	}
	
	template <typename T>
	void List<T>::insertFirst(T Value)
	{
		Node<T>* newNode = new Node<T>;
		newNode->datum = Value;
		if (size == 0)
		{
			head = newNode;
			tail = newNode;
		}else
		{
			newNode->next = head;
			head = NewNode;
		}
		size ++;
	}
	
	template <typename T>
	void List<T>::insertAfter(T Value, Node<T>* before)
	{
		if(before != NULL)
		{
			Node<T>* newNode= new Node<T>;
			newNode->datum = Value;
			newNode->next = before->next;
			before->next = newNode;
			size++;
		}
	}
	
	template <typename T>
	void List<T>:: insertLast(T Value)
	{
		Node<T>* newNode = new Node<T>;
		newNode->datum = Value;
		if (size == 0)
			{
				head = newNode;
				tail = newNode;
			}else
			{
				new newNode->next = NULL;
				tail->next = newNode;
				tail = newNode;
			}
		size ++;
	}
	
	template <typename T>
	Node<T>* List<T>::Find(T Value)
	{
		Node<T>* current = head;
		while (current != NULL)
		{
			if (current->datum = Value)
				return current;
			current = current->next;
		}
		return NULL;
	}
	template <typename T1>
	ostream& operator<<(ostream& lhs, list<T1> rhs)
	{
		node<T1>* current = rhs.head;
		while(current != NULL)
		{
			lhs << current->datum << " ";
			current = current->next;
		}
		return lhs;
	}
	template<typename T>
	int List<T>::getSize()const
	{
		return size;
	}
	
	template <typename T>
	List<T>::~List();
	
	template <typename T>
	Iterator<T> List<T>::begin()
	{
		Iterator<T> ret(head);
		return ret;
	}
	
	Itemplate <typename T>
	terator<T> List<T>::end()
	{
		Iterator<T> ret(NULL);
		return ret;
	}

#endif
