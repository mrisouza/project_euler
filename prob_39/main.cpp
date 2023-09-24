/*

*/
#include <iostream>
#include <set>
#define MAX(a, b, c) ((a > b) ? (a > c ? a : c) : (b > c ? b : c))
#define MAX_PER 1000

bool is_right_triangle(int a, int b, int c);

int main(){
    int num_sol_max = 0;
    int p_max;
    for(int p = 1; p <= MAX_PER; p++){
        int num_sol = 0;
        for(int a = 1; a < 1000; a++){
            for(int b = 1; b < 1000; b++){
                if((p - a - b > 0)){
                    if(is_right_triangle(a, b, p - a - b)){
                        num_sol++;
                    }
                }
            }
        }
        num_sol = num_sol / 6;
        if(num_sol > num_sol_max){
            num_sol_max = num_sol;
            p_max = p;
        }
    }
    std::cout << p_max << std::endl;
    return EXIT_SUCCESS;
}

bool is_right_triangle(int a, int b, int c){
    std::set<int> sides{a, b, c};
    int hip = MAX(a, b, c);
    int sum_sq_cat = 0;
    for(const auto& side : sides){
        if(side != hip){
            sum_sq_cat += side * side;
        }
    }
    bool is_right = (sum_sq_cat == hip * hip);
    return is_right;
}
