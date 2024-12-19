#include <iostream>
#include <fstream>
#include "Matrix.hpp"
using namespace std;

void loadMatrixFromFile(const string& filename, int*& data, int& size) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> size;
        data = new int[size * size];
        for (int i = 0; i < size * size; ++i) {
            file >> data[i];
        }
        file.close();
    } else {
        cerr << "Unable to open file " << filename << endl;
    }
}

int main() {
    int* data;
    int size;

    // Wczytanie macierzy z pliku
    loadMatrixFromFile("matrix.txt", data, size);

    // Tworzenie macierzy
    Matrix m1(size, data);
    Matrix m2(size, data);
    Matrix m3;

    // Testowanie metod
    m3.alokuj(size);
    m3.losuj();
    cout << "losuj:\n" << m3 << endl;
    m3.wstaw(0, 0, 5);
    cout << "Element (0,0): " << m3.pokaz(0, 0) << endl;
    m3.odwroc();
    cout << "odwroc:\n" << m3 << endl;
    m3.diagonalna(data);
    cout << "diagonalna:\n" << m3 << endl;
    m3.diagonalna_k(-1, data);
    cout << "diagonalna_k(-1):\n" << m3 << endl;
    m3.kolumna(0, data);
    cout << "kolumna(0):\n" << m3 << endl;
    m3.wiersz(0, data);
    cout << "wiersz(0):\n" << m3 << endl;
    m3.przekatna();
    cout << "przekatna:\n" << m3 << endl;
    m3.pod_przekatna();
    cout << "pod_przekatna:\n" << m3 << endl;
    m3.nad_przekatna();
    cout << "nad_przekatna:\n" << m3 << endl;
    m3.szachownica();
    cout << "szachownica:\n" << m3 << endl;

    // Operatory
    Matrix m4 = m1 + m2;
    Matrix m5 = m1 * m2;
    Matrix m6 = m1 + 5;
    Matrix m7 = m1 * 5;
    Matrix m8 = m1 - 5;
    m1 += 5;
    m1 -= 5;
    m1 *= 5;
    m1++;
    m1--;

    // Porównania
    bool isEqual = (m1 == m2);
    bool isGreater = (m1 > m2);
    bool isLess = (m1 < m2);

    // Wyświetlanie macierzy
    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;
    cout << m4 << endl;
    cout << m5 << endl;
    cout << m6 << endl;
    cout << m7 << endl;
    cout << m8 << endl;

    // Zwolnienie pamięci
    delete[] data;

    return 0;
}