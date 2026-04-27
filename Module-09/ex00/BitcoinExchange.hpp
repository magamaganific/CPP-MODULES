#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <algorithm>
# include <map>
# include <iostream>
# include <string>

class DatesValues{
public:
	DatesValues();
	DatesValues(std::string input);
	DatesValues(const DatesValues &old);
	DatesValues &operator=(const DatesValues &old);
	~DatesValues();

	DatesValues &operator[](unsigned int i);
	unsigned int size() const;

	void saveTxt(std::string input);
	void saveCsv(std::string database);
	void saveDate(std::string line);

	class InvalidTxtFormatException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
	class InvalidCsvFormatException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
	class InvalidDateException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
private:
	std::map<int, int, int> _date;
	float _value;
};

#endif