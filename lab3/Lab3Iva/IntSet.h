#include <ostream>
#include <iostream>
#include <cstring>

using namespace std;



class IntSet {
private:
	int* set; //������
	int currentElements; //������� ��������� ������
	

public:
	

	static int maxElements;  //�� ��������

	IntSet(const IntSet& other); // Copy constructor (instead of op=)

	IntSet();

	IntSet(const int* sourceArray, int sourceArrayLen);

	IntSet(int max);

	~IntSet();

	bool isMember(int element);

	void insert(int element);

	friend ostream& operator>>(const IntSet& obj, ostream& os);

	friend istream& operator<<(IntSet& obj, istream& is);

	IntSet& operator=(const IntSet& other) { //�����������
		if (this == &other) return *this;

		delete[] set; //������ ������
		set = nullptr;

		currentElements = other.currentElements; //� ��� ��� ��������� �� ������
		set = currentElements ? new int[maxElements] : nullptr;
		copy(other.set, other.set + maxElements, set);
	}

	
	friend IntSet operator+(IntSet lhs, const IntSet& rhs) { // �������� +
		for (int i = 0; i < rhs.currentElements; i++) // �������� �� ���� ��������� ������ �� +
		{
			lhs.insert(rhs.set[i]); // � ��������� �� � ����� ���������
		}
		return lhs;
	}

	friend IntSet operator-(IntSet lhs, const IntSet& rhs) { //�������� �� ������ ��������� ������
		for (int i = 0; i < rhs.currentElements; i++) // �������� �� ����� ��������
		{ 
			for (int j = 0; j < lhs.currentElements; ++j) {
				if (lhs.set[j] == rhs.set[i]) lhs.set[i] = INT_MAX; //� ���� ���� ����������, ������ ���, ��� ��� ��� ))) (*�� ������� ������, � ����� �� ����������, ��� ���*)
			}
		}
		return lhs;
	}



};

