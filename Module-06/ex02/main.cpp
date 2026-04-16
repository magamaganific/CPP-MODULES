#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
# include <string>

Base * generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return (new A());
			break;
		case 1:
			return (new B());
			break;
		case 3:
			return (new C());
			break;
	default:
		std::cout<<"Randomizer error"<<std::endl;
		break;
	}
}
void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout<<"The identified type is A"<<std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout<<"The identified type is B"<<std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout<<"The identified type is C"<<std::endl;
	else
		std::cout<<"Unknown"<<std::endl;
}
void identify(Base& p)
{
	void *foo = NULL;
	Base &unused = (Base &)foo;
	if (dynamic_cast<A &>(p))
	else if (dynamic_cast<B &>(p))
		std::cout<<"The identified type is B"<<std::endl;
	else if (dynamic_cast<C &>(p))
		std::cout<<"The identified type is C"<<std::endl;
	else
		std::cout<<"Unknown"<<std::endl;
}

int main(void)
{
	std::cout<<"✽"<<std::endl;
	return(0);
}