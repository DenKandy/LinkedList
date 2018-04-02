#include "stdafx.h"
#include "List.h"

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