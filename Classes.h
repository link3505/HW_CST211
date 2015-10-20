#ifndef LinkedList_H
#define LinkedList_H

using namespace std;

template<class T> class Node;
template<class T> class Iterator;

template<class T> 
class LinkedList
{
public:
	LinkedList() : m_head(0), m_tail(0) {}
	LinkedList(const LinkedList<T> &copy) : m_head(0), m_tail(0) { *this = copy; }
	~LinkedList() { Purge(); }
	LinkedList<T> &operator=(const LinkedList<T> &rhs);

	void setHead(Node<T> *head) { m_head = head; }
	void setTail(Node<T> *tail) { m_tail = tail; }
	Node<T> *getHead() { return m_head; }
	Node<T> *getTail() { return m_tail; }

	bool isEmpty() { return m_head == 0; }
	Node<T> &First() const { return m_head.m_data; }
	Node<T> &Last() const { return m_tail.m_data; }
	void Prepend(T *source);
	void Append(T *source);
	void Purge();
	Node<T>& Extract(T source);
	void InsertAfter(T target, T *source);
	void InsertBefore(T target, T *source);
	Iterator<T> Begin() { return Iterator(m_head->m_next); }
	Iterator<T> End() { return Iterator(m_tail->m_next); }

private:
	Node<T>* m_tail;
	Node<T>* m_head;
};

#include "LinkedList.inc"


template<class T>
class Node
{
public:
	Node();
	Node(const Node &copy) { *this = copy; }
	~Node();
	Node<T> &operator=(const Node &rhs) { if (this != &rhs) { m_data = rhs.m_data; m_next = rhs.m_next; m_prev = rhs.m_prev; } else { return *this } }

	void setData(T data) { m_data = data; }
	void setNext(Node<T> *next) { m_next = next; }
	void setPrev(Node<T> *prev) { m_next = prev; }
	T getData() { return m_data; }
	Node<T> *getNext() { return m_next; }
	Node<T> *getPrev() { return m_prev; }
	
private:
	T m_data;
	Node* m_next;
	Node* m_prev;
};


template<class T>
class Iterator
{
public:
	Iterator();
	Iterator(Node<T> *P) : m_node(P) {}
	~Iterator();
	Iterator &operator=(const Iterator &rhs) { if (this != &rhs) { m_node = rhs.m_node; return *this; } }
	
	bool operator==(const Iterator &rhs) { return m_node == rhs.m_node; }
	bool operator!=(const Iterator &rhs) { return m_node != rhs.m_node; }
	Iterator operator++() { m_node = m_node->m_next; return *this; }
	Iterator operator++(int) { Iterator temp = *this; m_node = m_node->m_next; return temp; }
	Iterator operator--() { m_node = m_node->m_prev; return *this; }
	Iterator operator--(int){ Iterator temp = *this; m_node = m_node->m_prev; return temp; }

private:
	Node* m_node;
};

#endif