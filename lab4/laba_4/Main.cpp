#include "Header.h"
#include <windows.h>
int main() {
	setlocale(0, "");
	Deque  d;
	d.push_back(11);
	d.push_back(22);
	d.push_back(33);
	printf("Do you want to print D-TURN? [y] for true, [n] for false\n");

	char q;
	cin >> q; 

	if (q == 'y')
		cout << d;
	else
		printf("\nContinuing with out printing... \n");

	q = NULL;
	printf("Do you want to see the list of commands?[y] for true, [n] for false\n");
	cin >> q;
	if (q == 'y')
	{
		printf("Formirating the list of commands");
		for (int dots = 0; dots < 3; dots++) {
			printf(".");
			Sleep(1000);
		}
		printf("\nList of commands:\n");
		printf("1. Deleting commands: /delete_front [NUMBER], /delete_back [NUMBER]; \n");
		printf("2. Adding commands: /add_front [NUMBER], /add_back [NUMBER]; \n");
		printf("3. Print all available elements: /print; \n");
		printf("4. Exit from programm: /exit; \n");
	}
	else {
		printf("\nContinuing with out printing... ");

	}

	string str;
	int n;
	while (str != "/exit") {
		cin >> str;
		if (str == "/add_back") {
			cin >> n;
			d.push_back(n);
		}

		else if (str == "/add_front") {
			cin >> n;
			d.push_front(n);

		}
		else if (str == "/delete_back") {
			if (!d.empty()) {
				d.pop_back();
			}
		}

		else if (str == "/delete_front") {
			if (!d.empty()) {
				d.pop_front();
			}
		}

		else if (str == "/print")
			cout << d << endl;

	}
	if (str == "/exit") {
		cout << "Cya later" << endl;
	}
		

	Iterator I(d);
	Deque d1;
	int el = I.peek();
	d1.push_back(el);
	I.next(); el = I.peek();
	d1.push_back(el);
	cout << d1;
	return 0;
}

