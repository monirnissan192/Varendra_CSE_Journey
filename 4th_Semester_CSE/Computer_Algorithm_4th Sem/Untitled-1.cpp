#include <iostream>
class A {
protected:
    int p;
public:
    int set_p() {
        std::cin >> p;
        return 0;
    }
};

class B: protected A {
public:
    int q;
    int set_q() {
        std::cin >> q;
        return 0;
    }
    int sum() {
        std::cout << "Summation: " << p + q << std::endl;
        return 0;
    }
};

int main() {
    B ob1;
    ob1.set_p();
    ob1.set_q();
    ob1.sum();
    return 0;
}