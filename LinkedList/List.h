#ifndef LIST_H

#define LIST_H
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
#endif // LIST_H

