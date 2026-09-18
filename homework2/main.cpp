#include <iostream>
#include "functions.h"

int main() {
    int x = 4, y = 6;
    double d1 = 3.2, d2 = 5.7;

    // Требуемая
    std::cout << "multiply<int>: " << multiply<int>(x, y) << std::endl;
    std::cout << "multiply<double>: " << multiply<double>(d1, d2) << std::endl;

    // Модифицированная с модулем рандома
    std::cout << "multiply_random<int>: " << multiply_random<int>(x, y) << std::endl;
    std::cout << "multiply_random<double>: " << multiply_random<double>(d1, d2) << std::endl;

    // Вывод типа
    std::cout << "multiply deduced: " << multiply(x, y) << std::endl;
    std::cout << "multiply deduced double: " << multiply(d1, d2) << std::endl;

    return 0;
}
