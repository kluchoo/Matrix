#include <ostream>
#ifndef A7F977BB_AE3A_48CD_A727_8AFC90710D10
#define A7F977BB_AE3A_48CD_A727_8AFC90710D10

/**
 * @class Matrix
 * @brief Klasa reprezentująca macierz.
 */
class Matrix {
    private:
    int n; /**< Rozmiar macierzy. */
    int** tab; /**< Tablica dwuwymiarowa przechowująca elementy macierzy. */
    public:
    /**
     * @brief Konstruktor domyślny.
     */
    Matrix();

    /**
     * @brief Konstruktor inicjalizujący macierz o rozmiarze n.
     * @param n Rozmiar macierzy.
     * @param t Tablica jednowymiarowa z wartościami do inicjalizacji.
     */
    Matrix(int n, int* t);

    /**
     * @brief Konstruktor kopiujący.
     * @param m Obiekt klasy Matrix do skopiowania.
     */
    Matrix(Matrix& m);

    /**
     * @brief Destruktor.
     */
    ~Matrix(void);

    /**
     * @brief Alokuje pamięć dla macierzy o rozmiarze n.
     * @param n Rozmiar macierzy.
     * @return Referencja do obiektu Matrix.
     */
    Matrix& alokuj(int n);

    /**
     * @brief Wstawia wartość do macierzy.
     * @param x Współrzędna x.
     * @param y Współrzędna y.
     * @param wartosc Wartość do wstawienia.
     * @return Referencja do obiektu Matrix.
     */
    Matrix& wstaw(int x, int y, int wartosc);

    /**
     * @brief Zwraca wartość z macierzy.
     * @param x Współrzędna x.
     * @param y Współrzędna y.
     * @return Wartość z macierzy.
     */
    int pokaz(int x, int y);

    Matrix& odwroc(void);
    Matrix& losuj(void);
    Matrix& losuj(int x);
    Matrix& diagonalna(int* t);
    Matrix& diagonalna_k(int k, int* t);
    Matrix& kolumna(int x, int* t);
    Matrix& wiersz(int y, int* t);
    Matrix& przekatna(void);
    Matrix& pod_przekatna(void);
    Matrix& nad_przekatna(void);
    Matrix& szachownica(void);

    /**
     * @brief Operator dodawania macierzy.
     * @param m Obiekt klasy Matrix do dodania.
     * @return Referencja do obiektu Matrix.
     */
    Matrix& operator+(Matrix& m);

    Matrix& operator*(Matrix& m);
    Matrix& operator+(int a);
    Matrix& operator*(int a);
    Matrix& operator-(int a);
    friend Matrix operator+(int a, Matrix& m);
    friend Matrix operator*(int a, Matrix& m);
    friend Matrix operator-(int a, Matrix& m);
    Matrix& operator++(int);
    Matrix& operator--(int);
    Matrix& operator+=(int a);
    Matrix& operator-=(int a);
    Matrix& operator*=(int a);
    // Matrix& operator(double);
    friend std::ostream& operator<<(std::ostream& o, Matrix& m);

    /**
     * @brief Operator porównania macierzy.
     * @param m Obiekt klasy Matrix do porównania.
     * @return True, jeśli macierze są równe.
     */
    bool operator==(const Matrix& m);

    bool operator>(const Matrix& m);
    bool operator<(const Matrix& m);
};

#endif /* A7F977BB_AE3A_48CD_A727_8AFC90710D10 */
