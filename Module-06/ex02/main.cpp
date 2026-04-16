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
			return(NULL);
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

static int i = 0;
static std::string classes[] = {"A", "B", "C"};

void identify(Base& p)
{
	if (i < 3)
	{
		void *foo = NULL;
		Base &unused = (Base &)foo;
		try
		{
			if(i == 0)
				unused = dynamic_cast<A &>(p);
			if(i == 1)
				unused = dynamic_cast<B &>(p);
			if(i == 2)
				unused = dynamic_cast<C &>(p);
			else
				std::cout<<"Unknown"<<std::endl;
			(void)unused;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			i++;
			identify(p);
			return ;
		}
		std::cout<<"The identified type is "<<classes[i]<<std::endl;
		i = 0;
	}
}

int main(void)
{
	std::cout<<"✽"<<std::endl;
	Base *rnd = generate();
	identify(rnd);
	identify(*rnd);
	return(0);
}