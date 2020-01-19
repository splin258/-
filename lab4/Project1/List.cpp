#include "List.h"
/*
* Инициализация пустого списка
*/
void my_list::create_node()
{
	struct List* temp;
	temp = new(struct List);
	temp->Rec.keeper = NULL;

	temp->Next = NULL;
	temp->Prev = NULL;
	return;
}
/*
* Функция очистки списка от мусора:
*/
void my_list::clear(List*& Head, List*& Tail) {

	if (!Head) return;

	Tail->Next = NULL;
	Head->Prev = NULL;

	for (Tail = Head->Next; Tail; Tail = Tail->Next) {

		delete Tail->Prev;
		Head = Tail;
	}

	delete Head;
	cout << "Список очищен";
}

/*
* Добавление элемента в начало
*/
void my_list::add_begin(List*& Head, List*& Tail, int x)
{

	List* element = new List;

	element->Rec.keeper = x;
	element->Next = 0;
	element->Prev = 0;


	Head->Prev = element;
	element->Next = Head;


	Head = element;

	Tail->Next = Head;
	Head->Prev = Tail;
}

/*
* Добавление элемента в конец
*/
void my_list::add_after(List*& Head, List*& Tail, int x)
{
	List* element = new List;

	element->Rec.keeper = x;
	element->Next = 0;
	element->Prev = 0;

	if (Tail) {

		Tail->Next = element;
		element->Prev = Tail;
	}

	if (!Head) Head = element;

	Tail = element;

	Tail->Next = Head;
	Head->Prev = Tail;
}

/*
* Функции сокращения списка от хвоста и налево:
*/
void my_list::delete_TailElement(List*& Head, List*& Tail) {

	Tail = Tail->Prev;
	delete Tail->Next;
	Tail->Next = Head;
	Head->Prev = Tail;
}

/*
* Функции сокращения списка от головы и направо:
*/
void my_list::delete_HeadElement(List*& Head, List*& Tail) {

	Head = Head->Next;
	delete Head->Prev;
	Tail->Next = Head;
	Head->Prev = Tail;
}

/*
* Вывод текущего списка на экран
*/
void my_list::display_list(List*& Head, List*& Tail)
{

	Tail = Head;

	do {
		cout.width(3);
		cout << Tail->Rec.keeper;
		Tail = Tail->Next;
	} while (Tail != Head);

	Tail = Head->Prev;

	cout << endl;
}

/*
* Функция копирования одного списка в хвост второго:
*/
void my_list::Copy_Func(List*& Head_1, List*& Head_2, List*& Tail_1, List*& Tail_2) {

	string how_method;
	List* Head_3 = NULL;
	List* Tail_3 = NULL;
	cout << "Текущий список:	";		display_list(Head_1, Tail_1);
	cout << "Копировать в:  ";	display_list(Head_2, Tail_2);

	Head_3 = Head_1;
	Tail_1 = Head_1;

	do {
		Tail_3 = Tail_1;
		Tail_1 = Tail_1->Next;
	} while (Tail_1 != Head_1);

	Head_3->Prev = Tail_3;
	Tail_3->Next = Head_3;

	Tail_3 = Head_3;

	do {
		add_after(Head_2, Tail_2, Tail_3->Rec.keeper);
		Tail_3 = Tail_3->Next;
	} while (Tail_3 != Head_3);

	Head_2->Prev = Tail_2;
	Tail_2->Next = Head_2;

	cout << "Результат: "; display_list(Head_2, Tail_2);
	how_method.clear();
	clear(Head_3, Tail_3);
}

/*
* Функция переноса всех чётных узлов в отдельный список:
*/
void my_list::New_List(List*& Head_1, List*& Head_2, List*& Tail_1, List*& Tail_2) {

	List* Head_3 = NULL;
	List* Tail_3 = NULL;
	List* Head_4 = NULL;
	List* Tail_4 = NULL;
	int count = 0;

	Tail_3 = Head_3;
	Tail_1 = Head_1;

	do {

		if (count % 2 == 0) add_after(Head_3, Tail_3, Tail_1->Rec.keeper);

		count++;
		Tail_1 = Tail_1->Next;
	} while (Tail_1 != Head_1);

	count = 0;
	Tail_2 = Head_2;

	do {

		if (count % 2 == 0) add_after(Head_4, Tail_4, Tail_2->Rec.keeper);

		count++;
		Tail_2 = Tail_2->Next;
	} while (Tail_2 != Head_2);

	Tail_4 = Head_4;

	do {

		add_after(Head_3, Tail_3, Tail_4->Rec.keeper);
		Tail_4 = Tail_4->Next;
	} while (Tail_4 != Head_4);

	cout << "Результат: ";

	clear(Head_4, Tail_4);
	display_list(Head_3, Tail_3);
	clear(Head_3, Tail_3);
}