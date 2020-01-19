#include <iostream>
#include <string>
#include "List.h"

template <typename T>
void menu(List<T> &list) {
	int choice = 0;
	T element;

	while (true) {
		std::cout << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "�������� ��������:" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "1. �������� � ������ ������" << std::endl;
		std::cout << "2. �������� � ����� ������" << std::endl;
		std::cout << "3. ������� �� ������ ������" << std::endl;
		std::cout << "4. ������� �� ����� ������" << std::endl;
		std::cout << "5. �������� ������" << std::endl;
		std::cout << "6. ������� ������ � �������" << std::endl;
		std::cout << "7. �����" << std::endl;
		std::cout << "> ";

		while (true) {
			std::cin >> choice;
			if (std::cin.peek() == '\n') {
				break;
			}
			else {
				std::cout << "Input error (integer expected):" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
			}
		}

		switch (choice) {
		case 1: {
			std::cout << "������� �������: " << std::endl << "> ";
			std::cin >> element;
			list.add_begin(element);
			break;
		}
		case 2: {
			std::cout << "������� �������: " << std::endl << "> ";
			std::cin >> element;
			list.add_end(element);
			break;
		}
		case 3: {
			list.remove_begin();
			break;
		}
		case 4: {
			list.remove_end();
			break;
		}
		case 5: {
			list.clear();
			break;
		}
		case 6: {
			list.show_list();
			break;
		}
		case 7: return;
		default: {
			std::cout << "������������ �������" << std::endl;
		}
		}
	}
}

int main(void) {
	setlocale(LC_ALL, "Rus");
	int choice = 0;
	
	while (true) {
		std::cout << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "�������� ��� ������ ��� ������: " << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "1. int" << std::endl;
		std::cout << "2. float" << std::endl;
		std::cout << "3. �����" << std::endl;
		std::cout << "> ";

		while (true) {
			std::cin >> choice;
			if (std::cin.peek() == '\n') {
				break;
			}
			else {
				std::cout << "Input error (integer expected):" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
			}
		}

		switch (choice) {
		case 1: {
			system("cls");
			List<int>* list = new List<int>();
			menu<int>(*list);
			break;
		}
		case 2: {
			system("cls");
			List<float>* list = new List<float>();
			menu<float>(*list);
			break;
		}
		case 3: exit(1);
		default: {
			std::cout << "�������� �������" << std::endl;
			break;
		}
		}
	}

	return 0;
}