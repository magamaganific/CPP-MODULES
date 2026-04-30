#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdio.h>

int main (void){
    std::map<std::string, float> mp;
    std::map<std::string, float>::const_iterator it = mp.begin();
    mp.insert(std::pair<std::string, float>("hi", 10.0));
    std::cout<<it->first<<std::endl;
    std::cout<<it->second<<std::endl;
    printf("hi\n");
}