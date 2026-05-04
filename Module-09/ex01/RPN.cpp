#include "RPN.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>

RPN::RPN(): result(0){}

RPN::RPN(std::string rpn): result(0){
	for(int index = 0; rpn[index]; index++)
	{
		checkRpn(rpn, index);
		if(isdigit(rpn[index]))
			stack.push(rpn[index] - 48);
		else if (stack.size() >= 2 && operatorIsValid(rpn[index]) == true)
		{
			operand.second = stack.top();
			stack.pop();
			operand.first = stack.top();
			stack.pop();
			if (rpn[index] == '/' && operand.second == '0')
				throw ": division by 0";
			result = (rpn[index] == '+') ? (operand.first + operand.second) :
				(rpn[index] == '-') ? (operand.first - operand.second) :
				(rpn[index] == '*') ? (operand.first * operand.second) :
				(operand.first / operand.second);
			stack.push(result);
		}
	}
	if (stack.size() == 1)
		std::cout<<stack.top()<<std::endl;
	else
		throw " ";
}

RPN::RPN(const RPN &old){
	this->operand = old.operand;
	this->result = old.result;
	this->stack = old.stack;
}

RPN &RPN::operator=(const RPN &old){
	if (this != &old)
	{
		this->operand = old.operand;
		this->result = old.result;
		this->stack = old.stack;
	}
	return (*this);
}

RPN::~RPN(){}

bool RPN::operatorIsValid(char operat)
{
	if(operat == '/' || operat == '+' || operat == '-' || operat == '*')
		return (true);
	return (false);
}

void RPN::checkRpn(std::string &rpn, int index){
	if (!isdigit(rpn[index]) && rpn[index] != ' ' 
	&& operatorIsValid(rpn[index]) == false && rpn[index] != ' ')
		throw ": invalid char";
	if (index == 0 && !isdigit(rpn[index]))
		throw "";
	else if (isdigit(rpn[index]) && rpn[index + 1] != ' ')
		throw "";
	else if (this->operatorIsValid(rpn[index]) && rpn[index + 1] != ' '
			&& rpn[index + 1] != 0)
		throw "";
	else if (this->operatorIsValid(rpn[index]) && stack.size() < 2)
		throw "";
}