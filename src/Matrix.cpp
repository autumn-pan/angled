#include "Matrix.hpp"

Matrix::Matrix(double **data)
{
    this->data = data;
}

void Matrix::setData(double **data)
{
    this->data = data;
}

Matrix* Matrix::mult(Matrix * m)
{
    if (this->cols != m->rows)
    {
        return nullptr;
    }

    double **result = new double*[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        result[i] = new double[m->cols];
        for (int j = 0; j < m->cols; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < this->cols; k++)
            {
                result[i][j] += this->data[i][k] * m->data[k][j];
            }
        }
    }
    return new Matrix(result);
}

Matrix* Matrix::add(Matrix * m)
{
    if (this->rows != m->rows || this->cols != m->cols)
    {
        return nullptr;
    }
    double **result = new double*[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        result[i] = new double[this->cols];
        for (int j = 0; j < this->cols; j++)
        {
            result[i][j] = this->data[i][j] + m->data[i][j];
        }
    }

    return new Matrix(result);
}

Matrix* Matrix::sub(Matrix * m)
{
    if (this->rows != m->rows || this->cols != m->cols)
    {
        return nullptr;
    }
    double **result = new double*[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        result[i] = new double[this->cols];
        for (int j = 0; j < this->cols; j++)
        {
            result[i][j] = this->data[i][j] - m->data[i][j];
        }
    }

    return new Matrix(result);
}

Matrix* Matrix::transpose()
{
    double **result = new double*[this->cols];
    for (int i = 0; i < this->cols; i++)
    {
        result[i] = new double[this->rows];
        for (int j = 0; j < this->rows; j++)
        {
            result[i][j] = this->data[j][i];
        }
    }
    return new Matrix(result);
}


Matrix* Matrix::scale()
{
    double **result = new double*[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        result[i] = new double[this->cols];
        for (int j = 0; j < this->cols; j++)
        {
            result[i][j] = this->data[i][j] * this->data[i][j];
        }
    }
    return new Matrix(result);
}

Matrix* generateIdenitityMatrix(int size)
{
    double **data = new double*[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = new double[size];
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                data[i][j] = 1;
            }
            else
            {
                data[i][j] = 0;
            }
            return nullptr;
        }
    }
    return new Matrix(data);
}

