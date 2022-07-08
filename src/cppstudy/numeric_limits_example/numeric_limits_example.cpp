
#include <iostream>
#include <limits>

int main () {
// smallest negative value:
    std::cout << std::numeric_limits<double>::lowest() << "\n";
// float/double: smallest value > 0
// integers: smallest value
    std::cout << std::numeric_limits<double>::min() << "\n";
// largest positive value:
    std::cout << std::numeric_limits<double>::max() << "\n";
// smallest difference btw. 1 and next value:
    std::cout << std::numeric_limits<double>::epsilon() << "\n";
}