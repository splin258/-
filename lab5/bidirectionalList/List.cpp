#ifndef __CPP_LIST__
#define __CPP_LIST__

#include "List.h"

template <typename T>
void List<T>::set_empty_points() { // ������� ������ ���� (����� � ����� ��������� ���� �� ����� (������ �� ������ ��������))
	Node<T>* node = new Node<T>();
	this->header = node;
	this->tail = node;

	this->tail->next = this->header;
	this->tail->prev = this->header;

	this->header->prev = this->tail;
	this->header->next = this->tail;
}

template <typename T>
List<T>::List() { //�����������. ����� ������ ���������� ����� � �����
	this->set_empty_points();
}

template <typename T>
List<T>::~List() { //����������
	this->clear(); //������� ��� ����������

	delete this->header; //������� ���� � �����
	delete this->tail;
}

template <typename T>
Node<T>* List<T>::create_node() {
	Node<T>* tmp = new Node<T>();

	return tmp;
}

template <typename T>
template <typename T1>
Node<T1>* List<T>::create_node() {
	Node<T1>* tmp = new Node<T1>();

	return tmp;
}

template <typename T>
Node<T>* List<T>::add_end(T _data) { //�������� � ����� ( � �����) ����� �������
	Node<T>* node = new Node<T>(); //������� ����� �������

	node->data = _data;
	node->next = this->header;
	node->prev = this->tail;

	this->header->prev = node;
	this->tail->next = node;
	
	if (!this->header->data) { //���� ������ ������� (��� �������)
		node->prev = node; //�� ������� ����� ��������� ��� �� ���� (������ �� ������ ��������)
		node->next = node;

		this->header = node;
	}

	this->tail = node; //��������� ������� � ������

	return node;
}

template <typename T>
Node<T>* List<T>::add_begin(T _data) { //�������� � ������ ( � �����) ����� �������
	Node<T>* node = new Node<T>(); //������� ����� �������

	node->data = _data; //��������� �������
	node->prev = this->tail;
	node->next = this->header;

	this->header->prev = node;//������� �� ���� ���������
	this->tail->next = node;

	if (!this->tail->data) {
		node->prev = node;
		node->next = node;

		this->tail = node;
	}

	this->header = node;//��������� � �����

	return node;
}

template <typename T>
void List<T>::clear() {
	while (this->tail->data) { //���� ���� ������, ������� �� ������ ��������
		this->remove_begin();
	}
}

template <typename T>
void List<T>::remove_end() {
	if (this->header == this->tail) { //���� ����� ����� ������, �� ��� ��������� �������
		this->set_empty_points(); //�������� ��������� ����
	}
	else {
		this->header->prev = this->tail->prev; //������� ��� ��������� �� ������ �������
		this->tail->prev->next = this->header;

		delete this->tail; //� ������� ���
		this->tail = this->header->prev;
	}
}

template <typename T>
void List<T>::remove_begin() {
	if (this->header == this->tail) {
		this->set_empty_points();
	}
	else {
		this->header->next->prev = this->tail;
		this->tail->next = this->header->next;

		delete this->header;
		this->header = this->tail->next;
	}
}

template <typename T>
void List<T>::show_list() {
	Node<T>* tmp = this->header;

	if (tmp == this->tail && !tmp->data) { //���� ������ �������
		std::cout << "List is empty" << std::endl;
		return;
	}

	do {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	} while (tmp != this->header);

	std::cout << std::endl;
}

#endif // !__CPP_LIST__