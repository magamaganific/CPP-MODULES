#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>

BitcoinExchange::BitcoinExchange(){
	std::ifstream data("data.csv");
	if (!data.is_open())
		throw (std::string) "Cannot open database";
	std::string line;
	getline(data, line);
	while (getline(data, line)){
		fillData(line);
	}
	data.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &old){
	this->LineData.date = old.LineData.date;
	this->LineData.value = old.LineData.value;

	for(std::map<std::string, float>::const_iterator it = old._data.begin();
		it != old._data.end(); it++){
		this->_data[it->first] = it->second;
	}
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &old)
{
	if (this != &old){
		this->LineData.date = old.LineData.date;
		this->LineData.value = old.LineData.value;

		this->_data.clear();
		for(std::map<std::string, float>::const_iterator it = old._data.begin();
			it != old._data.end(); it++){
			this->_data[it->first] = it->second;
		}
	}
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::printData(){
	std::map<std::string, float>::iterator it;
	for (it == this->_data.begin(); it != this->_data.end(); it++){
		std::cout<<it->first<<std::endl;
		std::cout<<it->second<<std::endl;
	}
}

void BitcoinExchange::fillData(std::string line){
	int i = 0;
	std::string key;
	std::stringstream ss(line);
	std::string token;
	while (getline(ss, token, ',')){
		if (i == 0){
			LineData.date = token;
			i++;
		}
		else
			LineData.value = atof(token.c_str());
	}
	this->_data.insert(std::make_pair(LineData.date, LineData.value));
}

void BitcoinExchange::handleInputFile(std::string fileName){
	int year;
	int month;
	int day;
	float value;
	char extra;

	std::string line;
	std::ifstream file(fileName.c_str());
	if(!file.is_open())
		throw (std::string) "Cannot open file";
	getline(file, line);
	if (line != "date | value")
		throw (std::string) "Invalid file header, expected: 'date | value'";
	bool firstline = true;
	while (getline(file, line)){
		if(firstline)
			firstline = false;
		if (line.length() < 14){
			std::cout<<"Error: Bad input =>"<<line<<std::endl;
			continue ;
		}
		else if(scanf(line.c_str(), "%d-%d-%d | %f%c", &year, &month, &day, &value, &extra) == 4){
			if(std::isspace(line[13]) || line[11] != '|' || line[line.length() - 1] == '.'){
				std::cout<<"Error: Bad input =>"<<line<<std::endl;
				continue ;
			}
			try{
				checkValue(value);
				checkDate(year, month, day);
			}
			catch (std::string e){
				std::cout<<"Error: "<<e<<std::endl;
				continue ;
			}
		}
		else{
			std::cout<<"Error: Bad input =>"<<line<<std::endl;
			continue ;
		}
		size_t pos = line.find(' ');
		LineData.date = line.substr(0, pos);
		LineData.value = value;
		findAndCalculateDate();
	}
	if (firstline)
		throw (std::string) "file is empty";
}

void BitcoinExchange::checkValue(float value){
	if (value < 0)
		throw (std::string) "not a positive number";
	if (value > 1000)
		throw (std::string) "too large a number";
}

void BitcoinExchange::checkDate(int year, int month, int day){
	int leapyear = 0;

	if (month < 1 || month > 12 || day > 31 || day < 1)
		throw (std::string) "invalid date";
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		leapyear = 1;
	int days[] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
	days[1] += leapyear;
	if (days[month - 1] < day)
		throw (std::string) "invalid date";
	if (year < 2009 || (year == 2009 && month == 1 && day < 2))
		throw (std::string) "min date: (2009-1-2)";
}

void BitcoinExchange::findAndCalculateDate(){
	std::map<std::string, float>::iterator it;
	it = this->_data.lower_bound(LineData.date);
	if (it == this->_data.end()){
		it--;
		std::cout<<std::setprecision(7)<<LineData.date<<" => "
			<<LineData.value<<" = "<< LineData.value * (*it).second<<std::endl;
		return ;
	}
	if (it == this->_data.begin()){
		it--;
		std::cerr<<"cannot find any closer data"<<std::endl;
		return ;
	}
	else{

	}
}
