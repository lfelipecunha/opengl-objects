#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"
Matrix::Matrix(int l, int c) {
    lines = l;
    columns = c;
    values = (float*) malloc(sizeof(float*) * lines * columns);
}

void Matrix::setValue(float value, int line, int column) {
    if ( (line * columns + column) >= (lines * columns) ) {
        throw;
    }

    values[line * columns + column] = value;
}

float Matrix::getValue(int line, int column) {
    if ( (line * columns + column) >= (lines * columns) ) {
        throw;
    }
    return values[line * columns + column];
}

int Matrix::getLines() {
    return lines;
}

int Matrix::getColumns() {
    return columns;
}

Matrix Matrix::operator*(const Matrix &value) const {
    Matrix actual = *this;
    Matrix other = value;
    if (actual.getLines() != other.getColumns()) {
        throw;
    }

    Matrix m(actual.getLines(),other.getColumns());

    for (int line=0; line < actual.getLines(); line++) {
        for (int i = 0; i < other.getColumns(); i++) {
            float sum = 0;
            for (int column=0; column < actual.getColumns(); column++) {
                sum += (actual.getValue(line,column)) *  (other.getValue(column,i));
            }
            m.setValue(sum,line,i);
        }
    }
    return m;
}

Matrix Matrix::operator+(const Matrix &value) const {
    Matrix actual = *this;
    Matrix other = value;
    if (actual.getLines() != other.getLines() || actual.getColumns() != other.getColumns()) {
        throw;
    }

    Matrix m(actual.getLines(),actual.getColumns());

    for (int line=0; line < actual.getLines(); line++) {
        for (int column=0; column < actual.getColumns(); column++) {
            float sum = actual.getValue(line,column) +  (other.getValue(line,column));
            m.setValue(sum,line,column);
        }
    }
    return m;
}

Matrix Matrix::operator-(const Matrix &value) const {
    Matrix actual = *this;
    Matrix other = value;
    if (actual.getLines() != other.getLines() || actual.getColumns() != other.getColumns()) {
        throw;
    }

    Matrix m(actual.getLines(),actual.getColumns());

    for (int line=0; line < actual.getLines(); line++) {
        for (int column=0; column < actual.getColumns(); column++) {
            float sum = actual.getValue(line,column) -  (other.getValue(line,column));
            m.setValue(sum,line,column);
        }
    }
    return m;
}

void Matrix::print() {
    for (int i=0; i<getLines();i++) {
        for (int j=0; j<getColumns();j++) {
            printf("%f\t",getValue(i,j));
        }
        printf("\n");
    }
}
