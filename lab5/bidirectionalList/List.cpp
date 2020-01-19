#ifndef __CPP_LIST__
#define __CPP_LIST__

#include "List.h"

template <typename T>
void List<T>::set_empty_points() { // заносим пустую ноду (шапка и хвост ссылаются друг на друга (список из одного элемента))
	Node<T>* node = new Node<T>();
	this->header = node;
	this->tail = node;

	this->tail->next = this->header;
	this->tail->prev = this->header;

	this->header->prev = this->tail;
	this->header->next = this->tail;
}

template <typename T>
List<T>::List() { //конструктор. Прсто делаем одинаковым шапку и хвост
	this->set_empty_points();
}

template <typename T>
List<T>::~List() { //диструктор
	this->clear(); //удаляем все еэелементы

	delete this->header; //удаляем шапу и хвост
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
Node<T>* List<T>::add_end(T _data) { //вставить в конец ( в хвост) новый элемент
	Node<T>* node = new Node<T>(); //создаем новый элемент

	node->data = _data;
	node->next = this->header;
	node->prev = this->tail;

	this->header->prev = node;
	this->tail->next = node;
	
	if (!this->header->data) { //если первый элемент (нет даннных)
		node->prev = node; //то элемент будет ссылаться сам на себя (список из одного элемента)
		node->next = node;

		this->header = node;
	}

	this->tail = node; //сохраняем элемент в голову

	return node;
}

template <typename T>
Node<T>* List<T>::add_begin(T _data) { //вставить в начало ( в шапку) новый элемент
	Node<T>* node = new Node<T>(); //создаем новый элемент

	node->data = _data; //заполняем данными
	node->prev = this->tail;
	node->next = this->header;

	this->header->prev = node;//создаем на него указатели
	this->tail->next = node;

	if (!this->tail->data) {
		node->prev = node;
		node->next = node;

		this->tail = node;
	}

	this->header = node;//вставляем в шапку

	return node;
}

template <typename T>
void List<T>::clear() {
	while (this->tail->data) { //пока есть данные, удаляем по одному элементу
		this->remove_begin();
	}
}

template <typename T>
void List<T>::remove_end() {
	if (this->header == this->tail) { //если шапка равна голове, то это последний элемент
		this->set_empty_points(); //обнуляем последнюю ноду
	}
	else {
		this->header->prev = this->tail->prev; //убираем все указатели на данный элемент
		this->tail->prev->next = this->header;

		delete this->tail; //и удаляем его
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

	if (tmp == this->tail && !tmp->data) { //если пустой элемент
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