#ifndef __H_LIST__
#define __H_LIST__

#include <iostream>

template <typename T> //��� ���� ������ � ������������ ������������� ������ ����� ������
struct Node { //Node - ������� ������ ������
	T data; //������ ������
	Node* next; //� ��������� �� ���������� � ��������� �������
	Node* prev;

	Node() {//������������� ��������
		this->data = T();//������ ������ ��� ������
		this->next = nullptr;//� ���� �� ���� ������
		this->prev = nullptr;
	}
};

template <typename T>
class List {
public:
	List(); //�����������
	~List(); //����������

	//�������� �������� �������� (�� ���������, �� ����������)
	Node<T>* create_node();
	template <typename T1>
	Node<T1>* create_node();//����� ������ ���� ��� ������ ��� ������� ��������

	Node<T>* add_end(T data); //������� � �����
	Node<T>* add_begin(T data); //������� � ������

	void clear(); //�������� ���� ������
	void remove_end(); //������� ��������� �������
	void remove_begin(); //������� ������ �������

	void show_list(); //�������� ������ � �������
private:
	Node<T>* header;
	Node<T>* tail;

	void set_empty_points(); //���������� � header � tail ������ node
};

#include "List.cpp"

#endif // !__H_LIST__

