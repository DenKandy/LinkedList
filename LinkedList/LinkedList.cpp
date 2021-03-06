// LinkedList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
//#include "List.h"
using namespace std;


template<class T>
class List
{
	struct Node
	{
		Node *next, *prev;
		T data;
	};
	Node *first, *last;
	size_t i;
public:
	List() : first( NULL ), last( NULL ) {}
	~List() {}
	size_t GetSize();
	void RemoveAll();
	void PushBack( T data );
	void PushFront( T data );
	void PopBack();
	void PopFront();
};


int main()
{
	List<int> lis = List<int>();
	lis.PushBack( 12 );
	lis.PushBack( 13 );
	lis.PushBack( 14 );
	lis.PushFront( 11 );
	lis.PushFront( 10 );
	lis.PopBack();
	lis.PopFront();
	lis.PushBack( 15 );

	system( "pause" );
    return 0;
}

template<class T>
void List<T>::PushBack( T data )
{
	Node *temp = new Node;
	temp->next = NULL;
	temp->data = data;
	i++;

	if ( first != NULL )
	{
		temp->prev = last;
		last->next = temp;
		last = temp;
	}
	else
	{
		temp->prev = NULL;
		first = last = temp;
	}

}
template<class T>
void List<T>::PushFront( T data )
{
	Node *temp = new Node;
	temp->prev = NULL;
	temp->data = data;
	i++;

	if ( first != NULL )
	{
		temp->next = first;
		first->prev = temp;
		first = temp;
	}
	else
	{
		temp->prev = NULL;
		first = last = temp;
	}
}
template<class T>
void List<T>::PopBack()
{
	Node *prev = last->prev;
	delete last;
	last = prev;
	i--;
}
template<class T>
void List<T>::PopFront()
{
	Node *next = first->next;
	delete first;
	first = next;
	i--;
}

template<class T>
size_t List<T>::GetSize()
{
	return i;
}

template<class T>
void List<T>::RemoveAll()
{
	Node *next = NULL;
	while ( first != NULL )
	{
		next = first->next;
		delete first;
		first = next;
		i--;
	}
}
