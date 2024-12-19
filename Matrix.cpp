#include "Matrix.hpp"
#include <stdlib.h>

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

int Matrix::pokaz(int x, int y) {
    if (tab != nullptr) {
        if (x < n && y < n) {
            return tab[x][y];
        }
    }
    return 0;
}

Matrix& Matrix::odwroc() {
    if (tab != nullptr) {
        int** newTab = new int* [n];
        for (int i = 0; i < n; i++) {
            newTab[i] = new int[n];
            for (int j = 0; j < n; j++) {
                newTab[i][j] = tab[j][i];
            }
        }

        // Deallocate old memory
        for (int i = 0; i < n; i++) {
            delete[] tab[i];
        }
        delete[] tab;

        // Assign new transposed matrix
        tab = newTab;
    }
    return *this;
}

Matrix& Matrix::losuj() {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] = rand() % 10;
            }
        }
    }
    return *this;
}

Matrix& Matrix::losuj(int x) {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] = 0; // Initialize all elements to 0
            }
        }
        for (int i = 0; i < x; i++) {
            int randX = rand() % n;
            int randY = rand() % n;
            tab[randX][randY] = rand() % 10; // Fill with random digit from 0 to 9
        }
    }
    return *this;
}

Matrix& Matrix::diagonalna(int* t) {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] = 0; // Initialize all elements to 0
            }
        }
        for (int i = 0; i < n; i++) {
            tab[i][i] = t[i]; // Set diagonal elements from array t
        }
    }
    return *this;
}

Matrix& Matrix::diagonalna_k(int k, int* t) {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] = 0; // Initialize all elements to 0
            }
        }
        if (k >= 0) {
            for (int i = 0; i < n - k; i++) {
                tab[i][i + k] = t[i]; // Set elements k positions above diagonal from array t
            }
        } else {
            for (int i = 0; i < n + k; i++) {
                tab[i - k][i] = t[i]; // Set elements k positions below diagonal from array t
            }
        }
    }
    return *this;
}

Matrix& Matrix::kolumna(int x, int* t) {
    if (tab != nullptr) {
        if (x < n) {
            for (int i = 0; i < n; i++) {
                tab[i][x] = t[i]; // Set column x from array t
            }
        }
    }
    return *this;
}

Matrix& Matrix::wiersz(int x, int* t) {
    if (tab != nullptr) {
        if (x < n) {
            for (int i = 0; i < n; i++) {
                tab[x][i] = t[i]; // Set row x from array t
            }
        }
    }
    return *this;
}
Matrix& Matrix::przekatna() {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] = (i == j) ? 1 : 0; // Set 1 on the diagonal and 0 elsewhere
            }
        }
    }
    return *this;
}

Matrix& Matrix::pod_przekatna() {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] = (i > j) ? 1 : 0; // Set 1 below the diagonal and 0 elsewhere
            }
        }
    }
    return *this;
}

Matrix& Matrix::nad_przekatna() {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] = (i < j) ? 1 : 0; // Set 1 above the diagonal and 0 elsewhere
            }
        }
    }
    return *this;
}


Matrix& Matrix::szachownica() {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] = (i + j) % 2; // Set 1 if sum of indices is odd, 0 otherwise
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator+(Matrix& m) {
    if (tab != nullptr && m.tab != nullptr) {
        if (n == m.n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    tab[i][j] += m.tab[i][j]; // Add corresponding elements
                }
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator*(Matrix& m) {
    if (tab != nullptr && m.tab != nullptr) {
        if (n == m.n) {
            int** newTab = new int* [n];
            for (int i = 0; i < n; i++) {
                newTab[i] = new int[n];
                for (int j = 0; j < n; j++) {
                    newTab[i][j] = 0;
                    for (int k = 0; k < n; k++) {
                        newTab[i][j] += tab[i][k] * m.tab[k][j]; // Multiply corresponding elements
                    }
                }
            }

            // Deallocate old memory
            for (int i = 0; i < n; i++) {
                delete[] tab[i];
            }
            delete[] tab;

            // Assign new multiplied matrix
            tab = newTab;
        }
    }
    return *this;
}

Matrix& Matrix::operator+(int a) {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] += a; // Add a to all elements
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator*(int a) {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] *= a; // Multiply all elements by a
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator-(int a) {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] -= a; // Subtract a from all elements
            }
        }
    }
    return *this;
}

Matrix operator+(int a, Matrix& m) {
    if (m.tab != nullptr) {
        for (int i = 0; i < m.n; i++) {
            for (int j = 0; j < m.n; j++) {
                m.tab[i][j] += a; // Add a to all elements
            }
        }
    }
    return m;
}

Matrix operator*(int a, Matrix& m) {
    if (m.tab != nullptr) {
        for (int i = 0; i < m.n; i++) {
            for (int j = 0; j < m.n; j++) {
                m.tab[i][j] *= a; // Multiply all elements by a
            }
        }
    }
    return m;
}

Matrix operator-(int a, Matrix& m) {
    if (m.tab != nullptr) {
        for (int i = 0; i < m.n; i++) {
            for (int j = 0; j < m.n; j++) {
                m.tab[i][j] = a - m.tab[i][j]; // Subtract all elements from a
            }
        }
    }
    return m;
}

Matrix& Matrix::operator++(int) {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j]++; // Increment all elements
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator--(int) {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j]--; // Decrement all elements
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(int a) {
    if (tab != nullptr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tab[i][j] += a; // Add a to all elements
            }
        }
    }
    return *this;
}