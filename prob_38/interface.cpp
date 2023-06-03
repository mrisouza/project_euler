#include <iostream>
#include <string>

#include "interface.h"

bool is_nine_digit(std::string& s){
    return (s.size() == 9);
}

bool is_pandigital(std::string& s){
    for(int i = 0; i < (int) s.size() - 1; i++){
        for(int j = i+1; j < (int) s.size(); j++){
            if(s[i] == s[j]){
                return false;
            }
        }
    }
    return true;
}
