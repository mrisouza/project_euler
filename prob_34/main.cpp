#include <iostream>
#include <cmath>
#include <string>

#define MAX 1000000

std::string circular(std::string num);
bool is_prime(size_t num);
void swap(std::string& s, size_t i);

int main(){
    size_t total = 0;
    for(size_t i = 2; i < MAX; i++){
        if(is_prime(i)){
            bool prime = true;
            std::string num_str = std::to_string(i);
            std::string circ = circular(num_str);
            while(circ.compare(num_str) != 0){
                prime = prime && is_prime((size_t) stoi(circ));
                circ = circular(circ);
            }
            if(prime){
                total++;
            }
        }
    }
    std::cout << total <<std::endl;
    return EXIT_SUCCESS;
}

std::string circular(std::string num){
    size_t i = 0;
    if(num.length() == 1){
        return num;
    } else {
        char tmp = num[0];
        while(i != num.length() - 1){
            swap(num, i);
            i++;
        }
        num[num.length() - 1] = tmp;
        return num;
    }
}

void swap(std::string& s, size_t i){
    s[i] = s[i+1];
}

bool is_prime(size_t num){
    if(num == 0 || num == 1){
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
