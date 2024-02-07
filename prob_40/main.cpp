#include<iostream>
#include<string>
#include<chrono>
#define MAX 1000000

std::string join_string(std::string total_string, std::string s){
    total_string += s;
    return total_string;
}

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    std::string s = "";
    size_t i = 1;
    while(s.length() < MAX){
        s = join_string(s, std::to_string(i));
        i++;
    }
    i = 1;
    size_t matches = 1;
    size_t total = 1; 
    for(const auto& c : s){
        if(i == matches){
            std::cout << i << " -> " << std::stoi(std::to_string(c)) - 48 << "\n";
            total *= std::stoi(std::to_string(c)) - 48;
            matches *= 10;
        }
        i++;
    }
    std::cout << total << "\n";
    auto end = std::chrono::high_resolution_clock::now();
    auto delta = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    std::cout << delta << "\n";
    return EXIT_SUCCESS;
}
