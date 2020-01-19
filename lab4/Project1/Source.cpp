#include "List.h"

/*
* Главное меню:
*/

void menu(my_list cl, List*& Head_1, List*& Tail_1, List*& Head_2, List*& Tail_2)
{
	int choice = 0, element;

	while (choice != 10)
	{
		cout << endl << "---------------------------" << endl;
		cout << endl << "Двусвязный циклический список" << endl;
		cout << endl << "---------------------------" << endl;
		cout << "1.Инициализация пустого списка" << endl;
		cout << "2.Уничтожение списка с освобождением памяти" << endl;
		cout << "3.Добавление узла в голову" << endl;
		cout << "4.Добавление узла в хвост" << endl;
		cout << "5.Удаление узла из головы" << endl;
		cout << "6.Удаление узла из хвоста" << endl;
		cout << "7.Выдача текущего списка" << endl;
		cout << "8.Добавить (скопировать) один список в хвост второго" << endl;
		cout << "9.Перенести (не копируя) все четные по порядку узлы в отдельный список" << endl;
		cout << "10.Выход" << endl;
		cout << "Введите действие: ";

		while (true)
		{
			cin >> choice;
			if (cin.peek() == '\n') {
				break;
			}
			else {
				cout << "Input error (integer expected):" << endl;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}
		}
		switch (choice)
		{
		case 1:
			cout << "Список инициализирован";
			cl.create_node();
			cout << endl;
			break;
		case 2:
			cl.clear(Head_1, Tail_1);
			cout << endl;
			break;
		case 3:
			cout << "Введите элемент: ";
			cin >> element;
			cl.add_begin(Head_1, Tail_1, element);
			cout << endl;
			break;
		case 4:
			cout << "Введите элемент: ";
			cin >> element;
			cl.add_after(Head_1, Tail_1, element);
			cout << endl;
			break;
		case 5:
			if (Head_1 == NULL)
			{
				cout << "Список пуст, невозможно удалить элемент" << endl;
				break;
			}
			cl.delete_HeadElement(Head_1, Tail_1);
			cout << endl;
			break;
		case 6:
			if (Head_1 == NULL)
			{
				cout << "Список пуст, невозможно удалить элемент" << endl;
				break;
			}
			cl.delete_TailElement(Head_1, Tail_1);
			cout << endl;
			break;
		case 7:
			cl.display_list(Head_1, Tail_1);
			break;
		case 8:
			cl.Copy_Func(Head_1, Head_2, Tail_1, Tail_2);
			break;
		case 9:
			cl.New_List(Head_1, Head_2, Tail_1, Tail_2);
			break;
		case 10:
			break;
		default:
			cout << "Неправильная команда" << endl;
		}
	}
}

void menu2(my_list cl, List*& Head_1, List*& Tail_1, List*& Head_2, List*& Tail_2)
{
	int choice = 0, element;

	while (choice != 10)
	{
		cout << endl << "---------------------------" << endl;
		cout << endl << "Двусвязный циклический список" << endl;
		cout << endl << "---------------------------" << endl;
		cout << "1.Инициализация пустого списка" << endl;
		cout << "2.Уничтожение списка с освобождением памяти" << endl;
		cout << "3.Добавление узла в голову" << endl;
		cout << "4.Добавление узла в хвост" << endl;
		cout << "5.Удаление узла из головы" << endl;
		cout << "6.Удаление узла из хвоста" << endl;
		cout << "7.Выдача текущего списка" << endl;
		cout << "8.Добавить (скопировать) один список в хвост второго" << endl;
		cout << "9.Перенести (не копируя) все четные по порядку узлы в отдельный список" << endl;
		cout << "10.Выход" << endl;
		cout << "Введите действие: ";

		while (true)
		{
			cin >> choice;
			if (cin.peek() == '\n') {
				break;
			}
			else {
				cout << "Input error (integer expected):" << endl;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}
		}
		switch (choice)
		{
		case 1:
			cout << "Список инициализирован";
			cl.create_node();
			cout << endl;
			break;
		case 2:
			cl.clear(Head_2, Tail_2);
			cout << endl;
			break;
		case 3:
			cout << "Введите элемент: ";
			cin >> element;
			cl.add_begin(Head_2, Tail_2, element);
			cout << endl;
			break;
		case 4:
			cout << "Введите элемент: ";
			cin >> element;
			cl.add_after(Head_2, Tail_2, element);
			cout << endl;
			break;
		case 5:
			if (Head_1 == NULL)
			{
				cout << "Список пуст, невозможно удалить элемент" << endl;
				break;
			}
			cl.delete_HeadElement(Head_2, Tail_2);
			cout << endl;
			break;
		case 6:
			if (Head_1 == NULL)
			{
				cout << "Список пуст, невозможно удалить элемент" << endl;
				break;
			}
			cl.delete_TailElement(Head_2, Tail_2);
			cout << endl;
			break;
		case 7:
			cl.display_list(Head_2, Tail_2);
			break;
		case 8:
			cl.Copy_Func(Head_2, Head_1, Tail_2, Tail_1);
			break;
		case 9:
			cl.New_List(Head_2, Head_1, Tail_2, Tail_1);
			break;
		case 10:
			break;
		default:
			cout << "Неправильная команда" << endl;
		}
	}
}

int main()
{
	int choice;//, element;
	setlocale(LC_ALL, "Rus");
	/// Важные элементы любого списка:
	List* Head_1 = NULL;
	List* Tail_1 = NULL;
	List* Head_2 = NULL;
	List* Tail_2 = NULL;
	my_list cl;
	my_list cl_2;
	while (1)
	{
		cout << endl << "---------------------------" << endl;
		cout << endl << "Выберите список" << endl;
		cout << endl << "---------------------------" << endl;
		cout << "1.Список №1" << endl;
		cout << "2.Список №2" << endl;
		cout << "3.Выход" << endl;
		cout << "Введите действие: ";
		while (true)
		{
			cin >> choice;
			if (cin.peek() == '\n') {
				break;
			}
			else {
				cout << "Input error (integer expected):" << endl;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}
		}
		switch (choice)
		{
		case 1:
		{
			system("cls");
			menu(cl, Head_1, Tail_1, Head_2, Tail_2);
			break;
		}
		case 2:
		{
			system("cls");
			menu2(cl_2, Head_1, Tail_1, Head_2, Tail_2);
			break;
		}
		case 3:
		{
			exit(1);
		}
		default:
			cout << "Неверная команда" << endl;
			break;
		}
	}
	return 0;
}