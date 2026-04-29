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

	void		saveTxt(std::string input);
	void		saveCsv(std::string database);
	std::string	saveDate(std::string line);
	float		saveVal(std::string line);

	std::map<std::string, int> getData();

private:
	std::map<std::string, float> _data;
};

#endif