#include <iostream>

using namespace std;

int main(){

    int ROWS = 3;
    int COLS = 3;
    int Qmatrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout<<Qmatrix[1][2];


    int **matrix = new int*[ROWS];
    for (int i = 0; i < ROWS; ++i) {
        matrix[i] = new int[COLS];
    }
    matrix[1][1] = 2137;

    int counter = 1;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = counter++;
        }
    }

    // Wyświetlanie macierzy
    std::cout << "Macierz:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}