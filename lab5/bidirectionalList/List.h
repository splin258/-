#ifndef __H_LIST__
#define __H_LIST__

#include <iostream>

template <typename T> //это чтоб делать с возможностью использования разных типов данных
struct Node { //Node - элемент нашего списка
	T data; //хранит данные
	Node* next; //и указатели на предыдущий и следующий элемент
	Node* prev;

	Node() {//инициализация элемента
		this->data = T();//просто делаем его пустым
		this->next = nullptr;//и чтоб не было мусора
		this->prev = nullptr;
	}
};

template <typename T>
class List {
public:
	List(); //конструктор
	~List(); //диструктор

	//тестовое создание элемента (не сохраняем, но возвращаем)
	Node<T>* create_node();
	template <typename T1>
	Node<T1>* create_node();//можно задать свой тип данных для каждого элемента

	Node<T>* add_end(T data); //вставка в хвост
	Node<T>* add_begin(T data); //вставка в голову

	void clear(); //очистить весь список
	void remove_end(); //удалить последний элемент
	void remove_begin(); //удалить первый элемент

	void show_list(); //показать список в консоли
private:
	Node<T>* header;
	Node<T>* tail;

	void set_empty_points(); //установить в header и tail пустой node
};

#include "List.cpp"

#endif // !__H_LIST__

