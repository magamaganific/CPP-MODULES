#include "Bureaucrat.hpp"

int main(void)
{
	try{
		{
			Bureaucrat lisa;
			lisa.decrement();
		}
		{
			Bureaucrat mario("Mario", 150);
			mario.increment();
		}
		// {
		// 	Bureaucrat lisa("Lisa", 1);
		// 	lisa.increment();
		// }
		// {
		// 	Bureaucrat mario("Mario", 150);
		// 	mario.decrement();
		// }
		// {
		// 	Bureaucrat hector("Hector", -1);
		// }
		// {
		// 	Bureaucrat luis("Luis", 151);
		// }
	}
	catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
	return(0);
}