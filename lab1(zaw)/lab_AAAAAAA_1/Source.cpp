#include <iostream>

#include "Phone.h"

int main() {

	Phone *phone1 = new Phone();
	phone1->set();
	std::cout << phone1->get_phone() << std::endl;

	Phone phone2("+7 910 1111111");
	phone2.get();

	Phone phone3(+7, 920, 2222222);
	phone3.get();

	return 0;
}