#include <iostream>
#include <string>
#include <algorithm>

#define MAX 1000000

bool is_palindrome(std::string s);
std::string convert_base_2(std::string s);

int main(){
    size_t total = 0;
    for(size_t i = 0; i < MAX; i++){
        if(is_palindrome(std::to_string(i))){
            if(is_palindrome(convert_base_2(std::to_string(i)))){
                //std::cout << i << " -> " << convert_base_2(std::to_string(i)) << std::endl;
                total += i;
            }
        }
    }
    std::cout << total << std::endl;
    return EXIT_SUCCESS;
}

bool is_palindrome(std::string s){
    size_t s_length = s.length();
    size_t middle = (s_length % 2 == 0) ? (s_length / 2 - 1) : (s_length - 1) / 2;
    bool palindrome = true;
    for(size_t i = 0; i <= middle; i++){
        palindrome = (palindrome && (s[i] == s[s_length - 1 - i]));
    }
    return palindrome;
}

std::string convert_base_2(std::string s){
    std::string result = "";
    size_t num = (size_t) stoi(s);
    while(num >= 2){
        size_t rem = num % 2;
        result.append(std::to_string(rem));
        num /= 2;
    }
    result.append(std::to_string(num));
    std::reverse(result.begin(), result.end());
    return result;
}
