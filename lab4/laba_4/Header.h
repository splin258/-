#pragma once
#include <iostream>
using namespace std;

class Element;
class Deque {


	Element* bot;
	int size;


public:

	friend class Iterator;
	Deque();
	~Deque();
	Deque(const Deque& lst);
	void push_back(int);
	void push_front(int);
	void pop_back();
	void pop_front();
	int peek();
	bool empty();
	Deque& operator=(const Deque&);
	//int& operator[](const int);
	friend ostream& operator << (ostream&, Deque&);

};
class Element {

	friend class Iterator;
	friend class Deque;
	Element* next;
	int data;

public:
	Element(int data);
	friend ostream& operator << (ostream&, Deque&);

};

class Iterator
{
	Element* curr = nullptr;
	Deque* D;

public:

	friend class Deque;
	int peek() { return curr->data; }

	Iterator(Deque& d) { D = &d; curr = d.bot; }
	void next() { curr = curr->next; }
	void reset() { curr = D->bot; }

	Element* current() { return curr; }
	Element* isEmpty() { if (curr == 0) return 0; else return curr; }

	void set(Element* p = 0) { curr = p; }


};
