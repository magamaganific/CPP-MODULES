#include "Bureaucrat.hpp"

int main(void)
{
	try{
		{
			Bureaucrat lisa("Lisa", 1);
			Form democracy("Democracy", 2, 3);

			lisa.decrement();
			lisa.signForm(democracy);
			std::cout<<lisa;
		}
		{
			Bureaucrat mario("Mario", 150);
			mario.increment();
			std::cout<<mario;
		}
		{
			Bureaucrat lisa("Lisa", 1);
			Form democracy("Democracy", 2, 3);

			lisa.decrement();
			lisa.decrement();
			lisa.decrement();
			lisa.signForm(democracy);
			std::cout<<lisa;
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