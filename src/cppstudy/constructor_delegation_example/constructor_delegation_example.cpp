
#include <iostream>

class Range {
    int a_;
    int b_;
public:
    // 1) special constructor
    explicit Range (int a, int b): a_{a}, b_{b} {
        if (b_ > a_) std::swap(a_,b_);
    }
    // 2) special [a,a] constructor - delegates to [a,b] ctor
    explicit Range (int a): Range{a,a} {}
    // 3) default constructor - delegates to [a,a] ctor
    Range (): Range{0} {}

    int A() { return a_; }
    int B() { return b_; }
};

int main () {
    Range r1;        // 3) ⇒ r1.a_: 0  r1.b_: 0
    Range r2 {3};    // 2) ⇒ r2.a_: 3  r2.b_: 3
    Range r3 {4,9};  // 1) ⇒ r3.a_: 4  r3.b_: 9
    Range r4 {8,2};

    std::cout << "r1:\t(" << r1.A() << ", " << r1.B() << ")\n";
    std::cout << "r2:\t(" << r2.A() << ", " << r2.B() << ")\n";
    std::cout << "r3:\t(" << r3.A() << ", " << r3.B() << ")\n";
    std::cout << "r4:\t(" << r4.A() << ", " << r4.B() << ")\n";
}