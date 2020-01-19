#include <iostream>
#include "IntSet.h"

void testIntSet() {
	cout << "Testing class...\n";

	cout << "With default constructor: ";
	IntSet def;
	def >> cout;

	cout << "\nWith predefined input: ";
	int arr[] = { 0, 100, 200, 300  };
	IntSet predef(arr, sizeof(arr) / sizeof(int));
	predef >> cout;

	//здесь начало
	cout << "\nWith user input:\n";
	IntSet user;
	user << cin;
	cout << "Appending '555' and '666'...\n";
	user.insert(555);
	user.insert(666);
	user >> cout;
}

void calculateExpression() {
	cout << "Calculating expression...\n";
	IntSet A;
	cout << "Enter A:\n";
	A << cin;

	IntSet B;
	cout << "Enter B:\n";
	B << cin;

	IntSet C;
	cout << "Enter C:\n";
	C << cin;

	IntSet D = A + B - C;
	D >> cout;
	cout << '\n';
}

int main() {
	IntSet::maxElements = 512; //мощность. Определяется для всех
	testIntSet(); // функция для проверки работы
	calculateExpression(); // реализует задачу

	system("pause");
	return 0;
}
