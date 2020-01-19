#include "Phone.h"

#include <regex>

Phone::Phone() { //конструктор, когда нет параметров
	this->city_code = 0; //все просто по нулям
	this->station_code = 0;
	this->number = 0;
}

Phone::Phone(int city_code, int station_code, int number) { //конструктор когда все значения передаем отдельно
	if (city_code == 0 || station_code == 0 || number == 0) { // проверяем что все значения положительны
		throw std::runtime_error("Data is not valid"); //иначе ошибка
	}

	this->city_code = city_code; //this - это сам класс
	this->station_code = station_code; //вносим значения в класс
	this->number = number;
}

Phone::Phone(std::string phone) { // тут все передаем строкой "+7 (...) .. - .. - ..."
	this->parse_phone_number(phone);
}

void Phone::parse_phone_number(std::string phone) {
	std::regex phone_reg("[()+ -]"); //регулярка - она поможет достать все эти символы ([]+ -)
	std::regex word("[a-zA-Z]");

	std::string ph = std::regex_replace(phone, phone_reg, ""); //и все эти символы удаляем (чтоб получить чистое число 7........)
	std::smatch smtch;
	bool search_word = std::regex_search(phone, smtch, word);

	if (search_word || ph.length() != 11) { // если осталось меньше чисел или больше - ошибка
		//throw std::runtime_error("Phone is not valid!"); //ошибка
		std::cout << "Phone is not valid!" << std::endl;
		exit(0);
		return;
	}

	this->city_code = std::stoi(ph.substr(0, 1)); //вытаскиваем подстроку по позициям
	this->station_code = std::stoi(ph.substr(1, 3));
	this->number = std::stoi(ph.substr(4, 11));
}

//внесение данных
//void Phone::set_city_code(int code) { this->city_code = code; }
//void Phone::set_station_code(int code) { this->station_code = code; }
//void Phone::set_number(int code) { this->number = code;}
void Phone::set() {
	std::string str;
	std::cin >> str;

	this->parse_phone_number(str);
}
//возврат данных
int Phone::get_city_code() { return this->city_code; }
int Phone::get_station_code() { return this->station_code; }
int Phone::get_number() { return this->number; }
void Phone::get() {
	std::cout << this->get_phone() << std::endl;
}
//возвращает собранный номер телефон
std::string Phone::get_phone() {
	return  "+" + std::to_string(this->city_code) + " (" + std::to_string(this->station_code) + ") " + std::to_string(this->number);
}