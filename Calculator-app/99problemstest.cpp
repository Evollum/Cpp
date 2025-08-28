#include <iostream>

int main () {
    int N ;
    std::cout << "enter number:" ;
    std::cin >> N ;

    int result;
    if (N < 99) { 
        result = 199;
    } else if (N == 10000) {
        result = 9999;
    } else {
        result = (N / 100) * 100 + 99;
    } 
std::cout <<"For N = " << N << ", the result is:" << result << std::endl;

return 0;
}