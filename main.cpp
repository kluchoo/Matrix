#include <iostream>
#include "Matrix.hpp"
using namespace std;

int main() {
    int t[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Matrix m(3, t);
    Matrix m2(m);
    m2.wstaw(1, 1, 0);
    cout << m.pokaz(1, 1) << endl;
    cout << "test13\n";
    return 0;
}