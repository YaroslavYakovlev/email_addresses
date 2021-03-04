#include <iostream>

void PartOne(std::string strAddr){
    std::string strPatrOne;
    strPatrOne = strAddr.substr(0, strAddr.find("@"));
    std::cout << "strPatrOne: " << strPatrOne << std::endl;
}

void PartTwo(std::string strAddr){
    std::string strPartTwo;
    strPartTwo = strAddr.substr((strAddr.find("@") + 1), strAddr.length());
    std::cout << "strPartTwo: " << strPartTwo << std::endl;
}

int main()
{
    std::string strAddres;
    std::string strPatrOne;
    std::string strPartTwo;
	std::cout << "Emai addresses" << std::endl;
    std::cout << "Enter your email address" << std::endl;
    std::cin >> strAddres;
    std::cout << "strAddres: " << strAddres << std::endl;
    PartOne(strAddres);
    PartTwo(strAddres);
    return 0;
}