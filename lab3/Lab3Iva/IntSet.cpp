#include "IntSet.h"

int IntSet::maxElements;

// конструкторы
IntSet::IntSet() {
	set = nullptr;
	currentElements = 0;
}

IntSet::IntSet(const int* sourceArray, int sourceArrayLen) {
	set = new int[maxElements];
	for (int i = 0; i < sourceArrayLen; ++i) {
		set[i] = sourceArray[i];
	}
	currentElements = sourceArrayLen;
}

IntSet::IntSet(int max) : IntSet() { //вызываем и первый конструктор
	maxElements = max;
}

IntSet::IntSet(const IntSet& other) {
	currentElements = other.currentElements;
	set = nullptr;
	if (currentElements) {
		set = new int[maxElements];
		copy(other.set, other.set + maxElements, set);
	}
}

IntSet::~IntSet() {
	delete[] set; //чистим все
	set = nullptr;
}

ostream& operator>>(const IntSet& obj, ostream& os) { //вывод в консоль
	os << "IntSet(maxEls=" << IntSet::maxElements << ", els=[";
	for (int i = 0; i < obj.currentElements; ++i) {
		if (obj.set[i] == INT_MAX) continue; //выводим все, что не равно INT_MAX
		os << obj.set[i] << ", ";
	}
	os << "])";
	return os;
}

istream& operator<<(IntSet& obj, istream& is) { // ввод
	int len;
	cout << "Enter set length: ";
	is >> len; //вводим сколько элементов в массиве
	//	if (len < 0) { // Impossible since len is unsigned, just use max check
	//		cout << "Error: length < 0!\n";
	//		return is;
	//	}
	if (len > IntSet::maxElements) { //если больше, чем макс длина, говорим об этом
		cout << "Error: array exceeds max set size!\n";
		return is;
	}

	obj.currentElements = len;
	delete[] obj.set; // Does nothing if obj.set == nullptr

	obj.set = new int[IntSet::maxElements]; //вводим это все
	for (int i = 0; i < len; ++i) {
		cout << "Enter element #" << i << ": ";
		is >> obj.set[i];
	}

	return is;
}

bool IntSet::isMember(int element) { //проверка существования элемента во множестве
	if (set == nullptr) return false;
	for (int i = 0; i < currentElements; ++i) {
		if (set[i] == element) return true;
	}
	return false;
}

void IntSet::insert(int element) { //вставка во множество
	if (set == nullptr) {
		set = new int[maxElements];
		set[0] = element;
		currentElements = 1;
		return;
	}
	if (isMember(element)) return; //если уже есть, не добавляем

	if (currentElements + 1 > maxElements) {
		cout << "Error: max set size exceeded!\n";
		return;
	}
	set[currentElements] = element;
	currentElements++;
}


