#ifndef A7F977BB_AE3A_48CD_A727_8AFC90710D10
#define A7F977BB_AE3A_48CD_A727_8AFC90710D10

class Matrix {
    private:
    int n;
    int** tab;
    public:
    Matrix();
    Matrix(int n, int* t);
    Matrix(Matrix& m);
    ~Matrix(void);


    Matrix& alokuj(int n);
    Matrix& wstaw(int x, int y, int wartosc);
    int pokaz(int x, int y);
    Matrix& odwroc(void);
};



#endif /* A7F977BB_AE3A_48CD_A727_8AFC90710D10 */
