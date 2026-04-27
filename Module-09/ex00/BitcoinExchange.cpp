#include "BitcoinExchange.hpp"
#include <fstream>

DatesValues::DatesValues(){}

DatesValues::DatesValues(std::string database){
	if (database.substr(database.size() - 4) == ".txt")
		saveTxt(database);
	else if (database.substr(database.size() - 4) == ".csv")
		saveCsv(database);
	else
		throw (InvalidCsvException());
}

DatesValues::DatesValues(const DatesValues &old): _data(old._data){}


DatesValues &DatesValues::operator=(const DatesValues &old)
{
	*this = old;
	this->_data = old._data;
	return (*this);
}

DatesValues::~DatesValues(){}

void DatesValues::saveTxt(std::string input){
	std::fstream file;
	std::string date;
	int amount;

	file.open(input, std::ios::in);
	if(file.is_open())
	{
		std::string read;
		getline(file, read);
		if (read != "date | value")
			throw (InvalidTxtException());
		while (getline(file, read))
		{
			date = saveDate(read);
			amount = saveVal(read.substr(13));
		}
	}
}

void DatesValues::saveCsv(std::string database){
	std::fstream file;
	std::string date;
	int val;

	file.open(database, std::ios::in);
	if(file.is_open())
	{
		std::string read;
		getline(file, read);
		if (read != "date,exchange_rate")
			throw (InvalidCsvException());
		while (getline(file, read))
		{
			date = saveDate(read);
			val = saveVal(read.substr(10));
		}
	}
}

std::string DatesValues::saveDate(std::string line)
{
	std::string substr;
	int year;
	int month;
	int day;

	substr = line.substr(0, 4);
	for (int i = 0; i < 4; i++)
	{
		if(!isdigit(substr[i]))
			throw(InvalidDateException());
	}
	year = atol(substr.c_str());
}
