#pragma once
#include<iostream>
#include <string>

class Phone
{

public:
	//конструкторы
	Phone();
	Phone(std::string phone);
	Phone(int city_code, int station_code, int number);

	//методы внесения данных
	//void - пустой тип (ничего не нужно возвращать)
	void set();
	void get();
	//std::string - строка
	std::string get_phone(); //метод получения конечного телефона (+7 (...) .. - .. - ...)
	int get_city_code(); //возвращение данных
	int get_station_code();
	int get_number();

// данные класса (код города и т.д.)
private:
	void parse_phone_number(std::string);
	int city_code;
	int station_code;
	int number;
};

