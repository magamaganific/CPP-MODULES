#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <algorithm>
# include <map>
# include <iostream>
# include <string>

class BitcoinExchange{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &old);
	BitcoinExchange &operator=(const BitcoinExchange &old);
	~BitcoinExchange();

	void	fillData(std::string line);
	void	handleInputFile(std::string fileName);
	void	checkValue(float value);
	void	checkDate(int year, int month, int day);
	void	printData();
	void	findAndCalculateDate();
private:
	std::map<std::string, float> _data;
	struct{
		std::string	date;
		float		value;
	} LineData;
};

#endif