/* LU DECOMPOSITION IN C++

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: March 4th, 2022 */

#include <iostream>

#include "LUDecomposition.hpp"

using namespace std;

int main(){

    int linhas;
    int colunas;

    cin >> linhas >> colunas;

    double **matrix;

    matrix = new double *[linhas];

    for(unsigned i = 0; i < linhas; i++){

        matrix[i] = new double[colunas];

    }

    for(unsigned i = 0; i < linhas; i++){

        for(unsigned j = 0; j < colunas; j++){

            cin >> matrix[i][j];

        }

    }

    lu_decomposition(linhas, colunas, matrix);

    for(unsigned i = 0; i < linhas; i++){

        delete(matrix[i]);

    }

    delete(matrix);

    return 0;

}