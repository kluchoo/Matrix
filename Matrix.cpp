#include "Matrix.hpp"

Matrix::~Matrix() {
    for (int i = 0; i < n; i++) {
        delete[] tab[i];
    }
    delete[] tab;
}

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

Matrix::Matrix(Matrix& m) : n(m.n) {
    tab = new int* [n];
    for (int i = 0; i < n; i++) {
        tab[i] = new int[n];
        for (int j = 0; j < n; j++) {
            tab[i][j] = m.tab[i][j];
        }
    }
}

Matrix& Matrix::alokuj(int n) {
    if (tab == nullptr) {
        // Allocate memory if not already allocated
        this->n = n;
        tab = new int* [n];
        for (int i = 0; i < n; i++) {
            tab[i] = new int[n];
        }
    } else {
        if (this->n != n) {
            // If current allocation size is different, deallocate and reallocate
            for (int i = 0; i < this->n; i++) {
                delete[] tab[i];
            }
            delete[] tab;

            this->n = n;
            tab = new int* [n];
            for (int i = 0; i < n; i++) {
                tab[i] = new int[n];
            }
        }
        // If current allocation size is equal, do nothing
    }
    return *this;
}

Matrix& Matrix::wstaw(int x, int y, int wartosc) {
    if (tab != nullptr) {
        if (x < n && y < n) {
            tab[x][y] = wartosc;
        }
    }
    return *this;
}
