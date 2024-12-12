#include "Matrix.hpp"

Matrix::Matrix() : n(0), tab(nullptr) {}

Matrix::Matrix(int n, int* t) : n(n) {
    tab = new int* [n];
    for (int i = 0; i < n; i++) {
        tab[i] = new int[n];
        for (int j = 0; j < n; j++) {
            tab[i][j] = t[i * n + j];
        }
    }
}