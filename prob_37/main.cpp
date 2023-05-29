#include <iostream>
#include <string>
#include <cmath>

bool is_prime(size_t num);
void truncate_left(std::string& s);
void truncate_right(std::string& s);

int main(){
    size_t total_primes = 0, total = 0;
    size_t i = 10;
    while(total_primes < 11){
        if(is_prime(i)){
            bool trunc_prime = true;
            std::string trunc_left = std::to_string(i);
            std::string trunc_right = std::to_string(i);
            while(trunc_left.size() != 1 && trunc_prime){
                truncate_left(trunc_left);
                truncate_right(trunc_right);
                trunc_prime = trunc_prime && is_prime((size_t) std::stoi(trunc_left)) && is_prime((size_t) std::stoi(trunc_right));
            }
            trunc_prime = trunc_prime && is_prime((size_t) std::stoi(trunc_left)) && is_prime((size_t) std::stoi(trunc_right));
            if(trunc_prime){
                std::cout << i << std::endl;
                total_primes++;
                total += i;
            }
        }
        i++;
    }
    std::cout << total << std::endl;
    return EXIT_SUCCESS;
}

bool is_prime(size_t num){
    if(num == 1 || num == 0){
        return false;
    } else {
        if(num == 2){
            return true;
        } else {
            size_t lim = (size_t) floor(pow((double) num, 0.5));
            for(size_t i = 2; i <= lim; i++){
                if(num % i == 0){
                    return false;
                }
            }
            return true;
        }
    }
}

void truncate_left(std::string& s){
    size_t i = 1;
    if(s.size() > 1){
        for(; i < s.size(); i++){
            s[i-1] = s[i];
        }
        s.pop_back();
    }
}

void truncate_right(std::string& s){
    if(s.size() > 1){
        s.pop_back();
    }
}