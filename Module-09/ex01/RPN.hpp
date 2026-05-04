#ifndef RPN_HPP
# define RPN_HPP
# include <algorithm>
# include <stack>
# include <iostream>
# include <string>

class RPN{
	private:
		struct{
			double first;
			double second;
		} operand;
		double result;
		std::stack<double> stack;
	public:
		RPN();
		RPN(std::string rpn);
		RPN(const RPN &old);
		RPN &operator=(const RPN &old);
		~RPN();

		bool operatorIsValid(char operat);
		void checkRpn(std::string &rpn, int index);
};
#endif
