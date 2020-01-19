#include <ostream>
#include <iostream>
#include <cstring>

using namespace std;



class IntSet {
private:
	int* set; //массив
	int currentElements; //сколько элементов сейчас
	

public:
	

	static int maxElements;  //це мощность

	IntSet(const IntSet& other); // Copy constructor (instead of op=)

	IntSet();

	IntSet(const int* sourceArray, int sourceArrayLen);

	IntSet(int max);

	~IntSet();

	bool isMember(int element);

	void insert(int element);

	friend ostream& operator>>(const IntSet& obj, ostream& os);

	friend istream& operator<<(IntSet& obj, istream& is);

	IntSet& operator=(const IntSet& other) { //перезапиись
		if (this == &other) return *this;

		delete[] set; //чистим старое
		set = nullptr;

		currentElements = other.currentElements; //а тут все переносим из нового
		set = currentElements ? new int[maxElements] : nullptr;
		copy(other.set, other.set + maxElements, set);
	}

	
	friend IntSet operator+(IntSet lhs, const IntSet& rhs) { // оператор +
		for (int i = 0; i < rhs.currentElements; i++) // проходим по всем элементам справа от +
		{
			lhs.insert(rhs.set[i]); // и вставляем их в левое множество
		}
		return lhs;
	}

	friend IntSet operator-(IntSet lhs, const IntSet& rhs) { //вычитаем из одного множества второе
		for (int i = 0; i < rhs.currentElements; i++) // проходим по обоим массивам
		{ 
			for (int j = 0; j < lhs.currentElements; ++j) {
				if (lhs.set[j] == rhs.set[i]) lhs.set[i] = INT_MAX; //и если есть совпадения, делаем вид, что его нет ))) (*Он слишком жирный, в экрвн не помещается, лол кек*)
			}
		}
		return lhs;
	}



};

