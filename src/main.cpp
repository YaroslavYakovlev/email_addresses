#include <iostream>

bool validator(std::string strAddr){
    bool error = true;
    for(int i = 0; i < strAddr.length(); i++){
        if(((strAddr[i] == '.') && (strAddr[i + 1] == '.')) || (strAddr[i] == '@') 
          || (strAddr[0] == '.') || ((strAddr.size() - 1) == '.') || (strAddr[i] == '"')
            || (strAddr[i] == '(') || (strAddr[i] == ')') || (strAddr[i] == ',')
              || (strAddr[i] == ':') || (strAddr[i] == ';') || (strAddr[i] == '<')
                || (strAddr[i] == '>') || (strAddr[i] == '[') || (strAddr[i] == ']')
                  || (strAddr[i] == '\\')){
            error = false;
        }
    }
    return error;
}

bool partOne(std::string strAddr){
    bool partOne = true;
    std::string strPatrOne;
    strPatrOne = strAddr.substr(0, strAddr.find("@"));
    if(strPatrOne.empty()){
        partOne = false;
    }
    std::cout << "strPatrOne: " << strPatrOne << std::endl;
    if((validator(strPatrOne) == false) || (strPatrOne.length() > 64)){
        partOne = false;
    }    
    return partOne;
}

bool partTwo(std::string strAddr){
    bool partTwo = true;
    std::string strPartTwo;
    strPartTwo = strAddr.substr((strAddr.find("@") + 1), strAddr.length());
    if(strPartTwo.empty()){
        partTwo = false;
    }
    std::cout << "strPartTwo: " << strPartTwo << std::endl;
    for(int i = 0; i < strPartTwo.length(); i++){
        if(strPartTwo[i] == '_'){
            partTwo = false;
        }
    }
    if((validator(strPartTwo) == false) || (strPartTwo.length() > 63)){
        partTwo = false;
    } 
    return partTwo;
}

int main()
{
    std::string strAddres;
    bool flag = false;
	std::cout << "Emai addresses" << std::endl;
    std::cout << "Enter your email address" << std::endl;
    std::cin >> strAddres;
    std::cout << "strAddres: " << strAddres << std::endl;
    for(int i = 0; i < strAddres.length(); i++){
        if(strAddres[i] == '@'){
            flag = true;
            break;
        }
    }
    if(((partOne(strAddres) == true) && (partTwo(strAddres) == true)) && flag){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl; 
    }
    return 0;
}