#include <iostream>
#include <string>
using namespace std;



unsigned fact(unsigned n);
unsigned fib(unsigned n);
unsigned mult(unsigned x, unsigned y);
unsigned power(unsigned x, unsigned y);
unsigned product(unsigned x, unsigned y);



int main() {
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;
    cout << "50th Fibonacci number is " << fib(50) << endl;
    return 0;
}




unsigned fact_helper(unsigned n, unsigned acc) {
    if (n <= 1) return acc;
    return fact_helper(n - 1, n * acc);
}
unsigned fact(unsigned n) {
    return fact_helper(n, 1);
}


unsigned fib_helper(unsigned n, unsigned a, unsigned b) {
    if (n == 0) return a;
    if (n == 1) return b;
    return fib_helper(n - 1, b, a + b);
}
unsigned fib(unsigned n) {
    return fib_helper(n, 0, 1);
}


unsigned mult_helper(unsigned x, unsigned y, unsigned acc) {
    if (y == 0) return acc;
    return mult_helper(x, y - 1, acc + x);
}
unsigned mult(unsigned x, unsigned y) {
    return mult_helper(x, y, 0);
}


unsigned power_helper(unsigned x, unsigned y, unsigned acc) {
    if (y == 0) return acc;
    return power_helper(x, y - 1, acc * x);
}
unsigned power(unsigned x, unsigned y) {
    return power_helper(x, y, 1);
}

unsigned product_helper(unsigned x, unsigned y, unsigned acc) {
    if (x > y) return acc;
    return product_helper(x + 1, y, acc * x);
}
unsigned product(unsigned x, unsigned y) {
    return product_helper(x, y, 1);
}

