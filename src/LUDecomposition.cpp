/* LU DECOMPOSITION IN C++

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: March 4th, 2022 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

#include "LUDecomposition.hpp"

using namespace std;

void print(int &m, int &n, double **matrix, int *Pivot, double PdU, int Info){

    cout << "   Matriz Lower (L):" << endl;

    double aux = 0;
    double aux2 = 1;

    double mL = m;
    double mU = m;
    double nL = m;
    double nU = n;

    if(m > n){

        nL = n;
        mU = n;

    }

    for(unsigned i = 0; i < mL; i++){

        for(unsigned j = 0; j < nL; j++){

            if(j < i){

                if(j == 0){

                    cout << "| ";

                }

                cout << setprecision(4) << fixed << matrix[i][j] << "  ";

                if(j == nL - 1){

                    cout << "|" << endl;

                }

            }

            else if(j == i){

                if(j == 0){

                    cout << "| ";

                }

                cout << setprecision(4) << fixed << aux2 << "  ";

                if(j == nL - 1){

                    cout << "|" << endl;

                }

            }

            else{

                if(j == 0){

                    cout << "| ";

                }

                cout << setprecision(4) << fixed << aux << "  ";

                if(j == nL - 1){

                    cout << "|" << endl;

                }

            }

        }

    }

    cout << endl << "   Matriz Upper (U):" << endl;

    for(unsigned i = 0; i < mU; i++){

        for(unsigned j = 0; j < nU; j++){

            if(j >= i){

                if(j == 0){

                    cout << "| ";

                }

                cout << setprecision(4) << fixed << matrix[i][j] << "  ";

                if(j == nU - 1){

                    cout << "|" << endl;

                }

            }

            else{

                if(j == 0){

                    cout << "| ";

                }

                cout << setprecision(4) << fixed << aux << "  ";

                if(j == nU - 1){

                    cout << "|" << endl;

                }

            }

        }

    }

    cout << endl << "Linhas pivotais: ";

    for(unsigned i = 0; i < m; i++){

        cout << setprecision(0) << fixed << Pivot[i] + 1;

        if(i != m - 1){

            cout << " ";

        }

        else{

            cout << endl;

        }

    }

    cout << "Determinante de A = LU: " << setprecision(4) << fixed << PdU << endl;

    cout << "Info: " << setprecision(0) << fixed << Info << endl << endl;

}

void lu_decomposition(int &m, int &n, double **matrix){

    cout << "\nDecomposicao LU com pivotacao parcial" << endl << endl;

    int Info = 0;

    double PdU = 1;

    int Pivot[m];

    for(unsigned i = 0; i < m; i++){

        Pivot[i] = i;

    }

    int p;
    double Amax;
    double t;
    int aux;
    double r;
    double Mult;

    for(unsigned j = 0; j < min(m, n); j++){

        p = j;

        Amax = fabs(matrix[j][j]);

        for(unsigned k = j + 1; k < m; k++){

            if(fabs(matrix[k][j]) > Amax){

                Amax = fabs(matrix[k][j]);
                p = k;

            }

        }

        if(p != j){

            for(unsigned k = 0; k < n; k++){

                t = matrix[j][k];
                matrix[j][k] = matrix[p][k];
                matrix[p][k] = t;

            }

            aux = Pivot[j];
            Pivot[j] = Pivot[p];
            Pivot[p] = aux;

            PdU *= (-1);

        }

        PdU *= matrix[j][j];

        if(fabs(matrix[j][j]) != 0){

            r = 1.0/matrix[j][j];

            for(unsigned i = j + 1; i < m; i++){

                Mult = matrix[i][j] * r;
                matrix[i][j] = Mult;

                for(unsigned k = j + 1; k < n; k++){

                    matrix[i][k] -= Mult * matrix[j][k];

                }

            }

        }

        else if(Info = 0){

            Info = j;

        }

    }

    print(m, n, matrix, Pivot, PdU, Info);

}
