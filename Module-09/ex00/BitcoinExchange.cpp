#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

DatesValues::DatesValues(){}

DatesValues::DatesValues(std::string database){
	if (database.substr(database.size() - 4) == ".txt")
		saveTxt(database);
	else if (database.substr(database.size() - 4) == ".csv")
		saveCsv(database);
	else
		std::cout<<"Error file."<<std::endl;
}

DatesValues::DatesValues(const DatesValues &old){
	*this = old;
}


DatesValues &DatesValues::operator=(const DatesValues &old)
{
	this->_data = old._data;
	return (*this);
}

DatesValues::~DatesValues(){}

void DatesValues::saveTxt(std::string input){
	std::fstream file;
	std::string date;
	float amount;

	file.open(input.c_str(), std::ios::in);
	if(file.is_open())
	{
		std::string read;
		getline(file, read);
		while (getline(file, read))
		{
			date = saveDate(read);
			if (read.substr(10, 3) != " | ")
				std::cout<<"Error substr."<<std::endl;
			else
				amount = saveVal(read.substr(13));
			std::pair<std::string, float> data(date, amount);
			this->_data.insert(this->_data.end(), data);
		}
	}
}

void DatesValues::saveCsv(std::string database){
	std::fstream file;
	std::string read;
	std::string date;
	float val;

	file.open(database.c_str(), std::ios::in);
	if(file.is_open())
	{
		while (getline(file, read))
		{
			if (read == "date,exchange_rate")
				getline(file, read);
			date = saveDate(read);
			if (read.substr(10, 1) != ",")
				std::cout<<"Error."<<std::endl;
			val = saveVal(read.substr(11));
			std::pair<std::string, float> data(date, val);
			this->_data.insert(this->_data.end(), data);
		}
	}
}

std::string DatesValues::saveDate(std::string line)
{
	std::string year;
	std::string month;
	std::string day;

	if (line.length() < 10)
		return (NULL);
	year = line.substr(0, 4); // [xxxx]-xx-xx
	month = line.substr(5,2); // xxxx-[xx]-xx
	day = line.substr(8,2); // xxxx-xx-[xx]
	for (int i = 0; i < 4; i++)
		if(!year[i] || !isdigit(year[i]))
			std::cout<<"Error year."<<std::endl;
	for (int i = 0; i < 2; i++)
		if(!month[i] || !day[i] || !isdigit(month[i]) || !isdigit(day[i]))
			std::cout<<"Error day month."<<std::endl;
	int y = atol(year.c_str());
	int m = atol(month.c_str());
	int d = atol(day.c_str());
	int leapyear = 0;

	if(y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
		leapyear = 1;
	int months[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int days[] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
	days[1] += leapyear;
	if (months[m - 1] != m || !(days[d - 1] >= d))
		std::cout<<"Error day month."<<std::endl;
	return(year + "-" + month + "-" + day);
}

float DatesValues::saveVal(std::string line){
	for (int i = 0; line[i] != 0; i++)
		if(!(isdigit(line[i]) || line[i] == '.'))
			std::cout<<"Error value."<<std::endl;
	return (atof(line.c_str()));
}
