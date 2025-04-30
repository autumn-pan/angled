#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix
{
    public:
        Matrix(double **data);
        void setData(double **data);
        Matrix* mult(Matrix * m);
        Matrix* add(Matrix * m);
        Matrix* sub(Matrix * m);
        Matrix* transpose();
        Matrix* inverse();
        Matrix* scale();
        double* minor(int row, int col);
        double* cofactor(int row, int col);
        Matrix* cofactor();
        Matrix* adjoint();

        int determinant();

    protected:
        int rows;
        int cols;
        double **data;
};

Matrix* generateIdenitityMatrix(int size);


#endif