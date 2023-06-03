#include <iostream>
#include <string>

#include "interface.h"

int main(){
    for(int i = 1; i < MAX; i++){
        std::string s = std::to_string(i);
        int j = 1;
        while(is_pandigital(s) && (s.size() < 9)){
            j++;
            s += std::to_string(i*j);
        }
        if(is_pandigital(s) && is_nine_digit(s)){
            std::cout << i << " " << s << std::endl;
        }
    }
    return EXIT_SUCCESS;
}
/* response: 935218704 */