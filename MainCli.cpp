#include <format>
#include <iostream>

#include "CliUserInterface.hpp"

int main()
{
    auto ui = CliUserInterface(std::cin, std::cout);
    
    ui.execute();
}