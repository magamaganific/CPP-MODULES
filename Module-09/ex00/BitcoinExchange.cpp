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

void DatesValues::saveTxt(std::string input){
	std::fstream file;
	file.open(input, std::ios::in);
	if(file.is_open())
	{
		std::string read;
		getline(file, read);
		if (read != "date | value")
			throw (InvalidTxtException());
	}
}

void DatesValues::saveCsv(std::string database){
	std::fstream file;
	file.open(database, std::ios::in);
	if(file.is_open())
	{
		std::string read;
		getline(file, read);
		if (read != "date,exchange_rate")
			throw (InvalidCsvException());
	}
}
