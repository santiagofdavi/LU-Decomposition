/* LU DECOMPOSITION IN C++

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: March 4th, 2022 */

#ifndef LUDECOMPOSITION_H
#define LUDECOMPOSITION_H

void print(int &m, int &n, double **matrix, int *Pivot, double PdU, int Info);

void lu_decomposition(int &m, int &n, double **matrix);

#endif