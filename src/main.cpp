#include <iostream>

bool validator(std::string strAddr){
    for(int i = 0; i < strAddr.length(); i++){
        if(((strAddr[i] == '.') && ((strAddr[i + 1] == '.') && (strAddr[i] != strAddr[strAddr.length() - 1])))
          || (strAddr[i] == '"') || (strAddr[i] == '(') || (strAddr[i] == ')') 
            || (strAddr[i] == ',') || (strAddr[i] == ':') || (strAddr[i] == ';') 
              || (strAddr[i] == '<') || (strAddr[i] == '>') || (strAddr[i] == '[') 
                || (strAddr[i] == ']') || (strAddr[i] == '\\') || (strAddr[i] == '@')){
            return false;
        }
    }
    if((strAddr[0] == '.') || (strAddr[strAddr.length() - 1] == '.')){
        return false;
    }
    return true;
}

bool validatorPartTwo(std::string strAddr){
    for(int i = 0; i < strAddr.length(); i++){
        if((strAddr[i] == '!') || (strAddr[i] == '#') || (strAddr[i] == '$')
            || (strAddr[i] == '%') || (strAddr[i] == '&') || (strAddr[i] == '\'')
              || (strAddr[i] == '*') || (strAddr[i] == '+') || (strAddr[i] == '-')
                || (strAddr[i] == '/') || (strAddr[i] == '=') || (strAddr[i] == '?')
                  || (strAddr[i] == '^') || (strAddr[i] == '_') || (strAddr[i] == '`')
                    || (strAddr[i] == '{') || (strAddr[i] == '}') || (strAddr[i] == '|')
                      || (strAddr[i] == '~')) {
                          return false;
                      }
    }
    return true;
}

bool partOne(std::string strAddr){
    std::string strPatrOne;
    strPatrOne = strAddr.substr(0, strAddr.find("@"));
    if(strPatrOne.empty()){
        return false;
    }
    std::cout << "strPatrOne: " << strPatrOne << std::endl;
    if(!validator(strPatrOne) || (strPatrOne.length() > 64)){
        return false;
    }    
    return true;
}

bool partTwo(std::string strAddr){
    std::string strPartTwo;
    strPartTwo = strAddr.substr((strAddr.find("@") + 1), strAddr.length());
    if(strPartTwo.empty()){
        return false;
    }
    std::cout << "strPartTwo: " << strPartTwo << std::endl;
    if(!validator(strPartTwo) || !validatorPartTwo(strPartTwo) || (strPartTwo.length() > 63)){
        return false;
    } 
    return true;
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
    if((partOne(strAddres) && partTwo(strAddres)) && flag){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl; 
    }
    return 0;
}