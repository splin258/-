#pragma once
#include<iostream>
#include <string>

class Phone
{

public:
	//������������
	Phone();
	Phone(std::string phone);
	Phone(int city_code, int station_code, int number);

	//������ �������� ������
	//void - ������ ��� (������ �� ����� ����������)
	void set();
	void get();
	//std::string - ������
	std::string get_phone(); //����� ��������� ��������� �������� (+7 (...) .. - .. - ...)
	int get_city_code(); //����������� ������
	int get_station_code();
	int get_number();

// ������ ������ (��� ������ � �.�.)
private:
	void parse_phone_number(std::string);
	int city_code;
	int station_code;
	int number;
};

