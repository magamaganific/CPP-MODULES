#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <algorithm>
# include <iostream>
# include <deque>
# include <vector>
# include <ctime>
# include <sstream>
# include <cstddef>

# define START(x) x + 1
# define BEFOR "\e[0;31m"
# define AFTER "\e[0;32m"
# define MAG "\e[0;35m"
# define RESET "\033[0m"
# define RED "\033[0;33m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"

class PmergeMe{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &old);
	PmergeMe &operator=(const PmergeMe &old);
	~PmergeMe();

	static void mergeInsertSortVector(std::vector<int> &container, int start, int end);
	static void mergeSortVector(std::vector<int> &container, int start, int mid, int end);
	static void insertSortVector(std::vector<int> &container, int start, int end);

	static void mergeInsertSortDeque(std::deque<int> &container, int start, int end);
	static void mergeSortDeque(std::deque<int> &container, int start, int mid, int end);
	static void insertSortDeque(std::deque<int> &container, int start, int end);

	static void runVector(std::vector<int> &container);
	static void runDeque(std::deque<int> &container);
};

void print(std::vector<int> &, std::deque<int> &);
void calculateTime(std::vector<int> &, std::deque<int> &, double &, double &);

#endif