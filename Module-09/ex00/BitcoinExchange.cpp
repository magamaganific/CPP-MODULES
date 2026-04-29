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
		throw (std::string) "Invalid File!";
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

static std::stringstream l;
static std::string f;

void DatesValues::saveTxt(std::string input){
	std::fstream file;
	std::string date;
	int amount;
	int line = 0;
	f = "(.txt)";

	file.open(input.c_str(), std::ios::in);
	if(file.is_open())
	{
		std::string read;
		getline(file, read);
		line++;
		if (read != "date | value")
			throw (std::string) "Invalid .txt Header!";
		while (getline(file, read))
		{
			line++;
			l << line;
			date = saveDate(read);
			if (read.substr(10, 3) != " | ")
				throw (std::string) ".txt format error in line "
						+ std::to_string(line);
			amount = saveVal(read.substr(13));
			this->_data.insert({date, amount});
		}
	}
}

void DatesValues::saveCsv(std::string database){
	std::fstream file;
	std::string date;
	int val;
	int line = 0;
	f = "(.csv)";

	file.open(database.c_str(), std::ios::in);
	if(file.is_open())
	{
		std::string read;
		getline(file, read);
		line++;
		if (read != "date,exchange_rate")
			throw (std::string) "Invalid .csv Header!";
		while (getline(file, read))
		{
			line++;
			l = line;
			date = saveDate(read);
			if (read.substr(10, 1) != ",")
				throw (std::string) ".csv format error in line "
						+ std::to_string(line);
			val = saveVal(read.substr(11));
			this->_data.insert({date, val});
		}
	}
}

std::string DatesValues::saveDate(std::string line)
{
	std::string year;
	std::string month;
	std::string day;

	year = line.substr(0, 4); // [xxxx]-xx-xx
	month = line.substr(5,2); // xxxx-[xx]-xx
	day = line.substr(8,2); // xxxx-xx-[xx]
	// checking dates are only numbers
	for (int i = 0; i < 4; i++)
		if(!year[i] || !isdigit(year[i]))
			throw(std::string) "Invalid year in line " + std::to_string(l) + f;
	for (int i = 0; i < 2; i++)
		if(!month[i] || !day[i] || !isdigit(month[i]) || !isdigit(day[i]))
			throw(std::string) "Invalid month or day in line " + std::to_string(l) + f;
	// checking date validity
	int y = atol(year.c_str());
	int m = atol(month.c_str());
	int d = atol(day.c_str());
	int leapyear = 0;

	if(y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) // check leapyear
		leapyear = 1;
	int months[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int days[] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
	days[1] += leapyear; // apply leapyear
	if (months[m - 1] != m || !(days[d - 1] >= d))
			throw(std::string) "Invalid month or day in line " + std::to_string(l) + f;
	return(year + "-" + month + "-" + day);
}

float DatesValues::saveVal(std::string line){
	for (int i = 0; line[i] != 0; i++)
		if(!(isdigit(line[i])))
			throw(std::string) "Invalid value in line " + std::to_string(l) + f;
	return (atof(line.c_str()));
}