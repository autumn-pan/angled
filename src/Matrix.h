#ifndef MATRIX_H
#define MATRIX_H

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
        int determinant();

        int getRows();
        int getCols();
        double ** getData();

    private:
        int rows;
        int cols;
        double **data;
};

Matrix* generateIdenitityMatrix(int size);


#endif