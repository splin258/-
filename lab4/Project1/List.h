#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
* Node Declaration
*/
struct For_Info {

	int keeper;
};

struct List {

	For_Info Rec;
	List* Next;
	List* Prev;
};
/*
* Class Declaration
*/
class my_list
{
public:
	void create_node();
	void add_begin(List*& Head, List*& Tail, int x);
	void add_after(List*& Head, List*& Tail, int x);
	void delete_TailElement(List*& Head, List*& Tail);
	void delete_HeadElement(List*& Head, List*& Tail);
	void display_list(List*& Head, List*& Tail);
	void Copy_Func(List*& Head_1, List*& Head_2, List*& Tail_1, List*& Tail_2);
	void New_List(List*& Head_1, List*& Head_2, List*& Tail_1, List*& Tail_2);
	void clear(List*& Head, List*& Tail);
	my_list() {};
	~my_list() {};
};