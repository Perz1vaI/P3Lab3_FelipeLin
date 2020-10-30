/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: felipelinzhao
 *
 * Created on October 30, 2020, 1:25 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


int** LlenarMatriz(int**, int);

int** InicializarMatriz(int);

void liberarMatriz(int**&, int);

void printMatrix(int**, int);

int Determinante(int**&, int);

int Cofactor(int**, int, int, int);

int** Adjunta(int**, int);

int** submatriz(int**&, int, int, int);

int par_impar(int, int);

int main(int argc, char** argv) {

    int menu;
    cout << "1. Calcular las matrices\n2. Salida\n";
    cout << "Ingrese la opcion: ";
    cin >> menu;
    while (menu != 2) {
        switch (menu) {
            case 1:
            {
                int size;
                int** Matrix = NULL;
                int** Matrix_Adjunta = NULL;
                int** Matrix_Inversa = NULL;

                cout << "Elija el tamaño de su matriz: " << endl;
                cin >> size;

                Matrix = InicializarMatriz(size);

                Matrix = LlenarMatriz(Matrix, size);

                printMatrix(Matrix, size);

                Matrix_Adjunta = InicializarMatriz(size);

                Matrix_Adjunta = Adjunta(Matrix,size);

                printMatrix(Matrix_Adjunta, size);
                
                liberarMatriz(Matrix, size);
                liberarMatriz(Matrix_Adjunta, size);

                break;
            }
            default:
            {
                cout << "No existe esa opcion\n";
                break;
            }
        }

        cout << "1. Calcular las matrices\n2. Salida\n";
        cout << "Ingrese la opcion: ";
        cin >> menu;

    }


}

int** InicializarMatriz(int size) {
    if (size > 0) {
        int** intArray = new int*[size];
        for (int i = 0; i < size; i++) {
            intArray[i] = new int[size];
        }
        return intArray;
    }
    return NULL;
}

int** LlenarMatriz(int** matriz, int size) {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matriz[i][j] = rand() % 19 - 9;
            }
        }
    }
}

void liberarMatriz(int**& matriz, int size) {
    if (matriz != NULL && size > 0) {
        for (int i = 0; i < size; i++) {
            if (matriz[i] != NULL) {
                delete[] matriz[i];
                matriz[i] = NULL;
            }
        }
        delete[] matriz;
        matriz = NULL;
    }
}

void printMatrix(int** matriz, int size) {
    if (size > 0 && matriz != NULL) {
        for (int i = 0; i < size; i++) {
            if (matriz[i] != NULL) {
                cout << "[";
                for (int j = 0; j < size; j++) {
                    cout << setw(2) << matriz[i][j] << " ";
                }
                cout << "]" << endl;
            }



        }
        cout << endl;
    }
}

int** Adjunta(int** matriz, int size) {
    int** matrizAdjunta = InicializarMatriz(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "SEXO" << endl;
            matrizAdjunta[i][j] = Cofactor(matriz, i, j, size);
        }
    }

    return matrizAdjunta;
}

int Cofactor(int** MatrizAdjunta, int fila, int columna, int size) {
    int calculo;
    int** submatriz_a = InicializarMatriz(size);
    submatriz_a = submatriz(MatrizAdjunta, fila, columna, size);
    calculo = par_impar(fila, columna) * Determinante(submatriz_a, size);

    return calculo;

}

int** submatriz(int**& MatrizCofactor, int fila, int columna, int size) {
    int** matriz_x = InicializarMatriz(size);

    int x = 0, y = 0,n=size-1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != fila && j != columna) {
                matriz_x[x][y] = MatrizCofactor[i][j];
                y++;
                if (y >= n) {
                    x++;
                    y = 0;
                }
            }
        }
    }

    return matriz_x;

}

int par_impar(int i, int j) {

    if (i + j % 2 == 0) {
        return 1;
    } else {
        return -1;
    }
}

int Determinante(int**& matrix, int size) {
    int valor;
    if (size == 2) {
        valor = matrix[0][0] * matrix[1][1] + matrix[0][1] * matrix[1][0];
    } else {
        for (int i = 0; i < size; i++) {
            valor += matrix[0][i] * Cofactor(matrix, 0, i, size);
        }
    }

    return valor;

}






