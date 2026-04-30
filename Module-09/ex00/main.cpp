#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main(int ac, char **av)
{
    if (ac == 2){
        try{
            BitcoinExchange data;
            data.handleInputFile(av[1]);
        }
        catch(std::string e){
            std::cout<<"Error: "<<e<<std::endl;
        }
    }
    else{
        std::cout<<"Invalid Input, please enter a .txt file"<<std::endl;
    }
}
