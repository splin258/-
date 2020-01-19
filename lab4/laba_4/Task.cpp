#include "Header.h"
#include <iostream>
using namespace std;

Deque::~Deque() //все чистим 
{
	Element* current = bot->next;
	Element* next = bot->next;

	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}

	bot->next = nullptr;

}

//конструкторы
Deque::Deque(const Deque& lst)
{
	 bot = nullptr;
	size = 0;
	Element* temp = lst.bot->next;
	while (temp != nullptr) //идем пока не конец списка
	{
		push_back(temp->data); //сохраняем
		temp = temp->next; //переходим к следующемему элементу
	}

}


Element::Element(int data) { //клнструктор элемента массива
	this->data = data;
	next = NULL;
}
Deque::Deque() {
	bot = NULL;
	size = 0;
}

void Deque::push_back(int data) {
		//вставка в конец списка
	
		Element* p = new Element(data); //создаем элемент
			
		if (bot == NULL)
		{
			p->next = p; //
			bot = p;
		}
		else
		{
			p->next = bot->next;
			bot->next = p;
			bot = p;
		}
		size++;
	
}


void Deque::push_front(int data) {
	//вставка в начало списка

	Element* t = new Element(data);

	if (bot == NULL)
	{
		t->next = t;
		bot = t;
	}
	else
	{
		t->next = bot->next;
		bot->next = t;

	}
	size++;
}



void Deque::pop_front() {  
	//удаление первого элемента коллекции
	//Если список не пустой
	if (bot != NULL)                  
	{
		//Обращаемся к началу списка с помощью вспомогательного указателя
		Element* temp = bot->next;             
		cout << "ЭЛЕМЕНТ " << temp->data << " УДАЛЕН" << endl;
		//Сдвиг начала списка
		bot->next = temp->next;             
		// освобождени динамической памяти
		delete temp;        
		size--;

	}
}

void Deque::pop_back() {                   

	Element* q = bot->next;
	Element* z = q;
	cout << "ЭЛЕМЕНТ " << bot->data << " УДАЛЕН" << endl;
	while (q->next != bot)
		q = q->next;
	delete bot;
	
	q->next = z;
	bot = q;

	size--;
	
}

int Deque::peek() {
	if (bot!=NULL)
		return bot->data;
}

bool Deque::empty() {
	return size == 0;
}

Deque& Deque::operator=(const Deque& lst)
{
	if (this == &lst)
	{
		return *this;
	}

	this->~Deque();

	Element* temp = lst.bot->next;

	while (temp != nullptr)
	{
		push_back(temp->data);
		temp = temp->next;
	}
	return *this;
}

ostream& operator<<(ostream& out, Deque& c)
{
	out << "Список: " << endl;
	
	Element* q = c.bot->next;

	do
	{
		out << q->data << " ";
		q = q->next;
	} while (q != c.bot->next);
	return out;
}

