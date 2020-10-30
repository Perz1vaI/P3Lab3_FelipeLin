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

int Cofactor(int**,int,int);

int Adjunta(int**);




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

                cout << "Elija el tamaño de su matriz: " << endl;
                cin >> size;

                Matrix = InicializarMatriz(size);

                Matrix = LlenarMatriz(Matrix, size);

                printMatrix(Matrix, size);

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
                matriz[i][j] = rand() % 20 - 9;
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

int Determinante(int**& matriz, int size) {
    
  
}






