#include "Bureaucrat.hpp"
#include <fstream>

int main(void)
{
	try{
		{
		// std::cout <<target.getName()<<" executed "<<this->getName()<<std::endl;
		std::ofstream ofs;
		std::string name = "name";
		ofs.open(name + "_shrubbery", std::ofstream::trunc | std::ofstream::out);
		ofs<<"                                                                   ☆\n\n";
		ofs<<"     ☆\n\n";
		ofs<<"                         _ ❈ ~ ,❈ , ~  ✧ ❈\n";
		ofs<<"                    _~(       ✿            ` ~  ´  ¨   * ❈\n";
		ofs<<"                  &     ✧              ✽                   * ❈\n";
		ofs<<"                 &   ✽     ✧               ✿                  3           ☆\n";
		ofs<<"           c~º~%ºg.                              ✧      ❀       &\n";
		ofs<<"        C*º       ❀ ❈    \"I drew this tree\"                      )\n";
		ofs<<"       S   ✧         3            -SheDaVinci     ✽      c~º~%ºg.\n";
		ofs<<"      .❈✧         ✽   ~           ✽                  C*º  ❀    ✧ º\n";
		ofs<<"        (8   ❀      )       ❀                     3S          ✿  3\n";
		ofs<<"          &       3                      ❀    ✿  .¨    ❀       ❈~\n";
		ofs<<"         S( ¨ ^ ¨      ❀      ✷ ⁔   ✶         ︵  8          )\n";
		ofs<<"          ✧❀    ✿       ⁔     _// ❀ _/ ,¨ ✿ ◠v/ *  &    ❀  3\n";
		ofs<<"           *8&*     ❀ ✯// ❀/ /         .✿  , / ✿  ✧ .¨ ^ ¨ \n";
		ofs<<"               & &. ✧.❀\\\\ /             V¨´,´❀  &··¨\n";
		ofs<<"                   ¨❈ ¨>|V/░    |\\       /´.✧··¨\n";
		ofs<<"                         \\░░/   /,\\\\ \\ |/\n";
		ofs<<"                           \\\\   ||  \\\\ \\\\\n";
		ofs<<"";
		ofs<<"";
		ofs<<"";
		ofs<<"";
		ofs<<"";
		ofs<<"";
		ofs<<"´´´´´```'''\"´'´´`´`´´´'``''`´```´´´´´```'''\"´'´´`´`´´´'``''`´```´`'´`´´`´'''\"\n\n";
		}
		// {
		// 	Bureaucrat lisa("Lisa", 1);
		// 	AForm democracy("Democracy", 2, 3);

		// 	lisa.decrement();
		// 	lisa.signForm(democracy);
		// 	std::cout<<lisa;
		// }
		// {
		// 	Bureaucrat mario("Mario", 150);
		// 	mario.increment();
		// 	std::cout<<mario;
		// }
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