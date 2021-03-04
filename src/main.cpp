#include <iostream>

int main()
{
    std::string strAddres;
    std::string strPatrOne;
	std::cout << "Emai addresses" << std::endl;
    std::cout << "Enter your email address" << std::endl;
    std::cin >> strAddres;
    std::cout << "strAddres: " << strAddres << std::endl;
    strPatrOne = strAddres.substr(0, strAddres.find("@"));   
    std::cout << "strPatrOne: " << strPatrOne << std::endl;
    return 0;
}