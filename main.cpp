#include <iostream>
#include "Matrix.hpp"
using namespace std;

int main() {
    int t[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Matrix m(3, t);
    Matrix m2(m);
    cout << "test1\n";
    m2.alokuj(4);
    cout << "test2\n";
    m2.wstaw(1, 1, 0);
    cout << "test3\n";
    cout << m2.pokaz(1, 1) << endl;
    cout << "test4\n";
    m2.odwroc();
    cout << "test5\n";
    m2.losuj();
    cout << "test6\n";
    m2.wstaw(1, 1, 8);
    cout << "test7\n";
    cout << m2.pokaz(1, 1) << endl;

    return 0;
}