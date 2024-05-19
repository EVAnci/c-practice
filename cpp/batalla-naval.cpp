#include <iostream>
#include <string>
#include <cstdlib> // Para srand() y rand()

int main() {
    int x, y;
    int i = 0;
    int row;
    char column;
    int attemps=0;
    int objective=0;
    int ascii_column;
    std::rand(); // init the seed of random

    do {
        if ((x<3 || x>10) && i!=0) {
            std::cout << "[!] Debes ingresar un número entre 3 y 10" << std::endl;
        }
        std::cout << "Ingrese la cantidad de filas: ";
        std::cin >> x;
        i++;
    }
    while (x<3 || x>10);

    i=0;
    do {
        if ((y<3 || y>10) && i!=0) {
            std::cout << "[!] Debes ingresar un número entre 3 y 10" << std::endl;
        }
        std::cout << "Ingrese la cantidad de columnas: ";
        std::cin >> y;
        i++;
    }
    while (y<3 || y>10);

    std::cout << "Creando un tablero de " << x << "x" << y << std::endl;
    int board[x][y];
    int probability[5] = {0,0,0,1,1};
    for (int i=0; i<x; i++) {
        if (i==0) {
            char leter=65; // look the ascii table
            std::cout << "  ";
            for (int j=65; j<y+65; j++) {
                leter = j;
                std::cout << leter << " ";
            }
            std::cout << std::endl;
        }
        std::cout << i+1 << " ";
        for (int j=0; j<y; j++) {
            int barco = probability[std::rand() % (sizeof(probability)/sizeof(int))];
            board[i][j] = barco;
            if (barco==1) {
                objective++;
            }
            // Descomentar la linea de stdout board para ver el tablero creado, y comentar la #
            // std::cout << board[i][j] << " ";
            std::cout << "# ";
        }
        std::cout << std::endl;
    }
    std::cout << "Se ha creado el tablero\nComenzando el juego..." << std::endl;
    do {
        do {
            std::cout << "Ingrese la fila a atacar (1 a " << x << "): ";
            std::cin >> row;
            if (row<1 || row>x) {
                std::cout << "La fila ingresada no es valida!" << std::endl;
            }
        }
        while (row<1 || row>x);
        char letter = 64 + y;
        do {
            std::cout << "Ingrese la columna a atacar (A a " << letter << "): ";
            std::cin >> column;
            if (column<65 || column>letter) {
                std::cout << "La columna ingresada no es valida!" << std::endl;
            }
        }
        while (column<65 || column>letter);
        ascii_column = static_cast<int>(column) - 65;
        if (board[row-1][ascii_column] == 1) {
            std::cout << "Has dado!" << std::endl;
            board[row-1][ascii_column] = 2;
            objective--;
        } else if (board[row-1][ascii_column] == 0){
            std::cout << "Has fallado" << std::endl;
            board[row-1][ascii_column] = 3;
        } else {
            std::cout << "Estas coordenadas ya fueron usadas" << std::endl;
        }
        for (int i=0; i<x; i++) {
            if (i==0) {
                char leter=65; // look the ascii table
                std::cout << "  ";
                for (int j=65; j<y+65; j++) {
                    leter = j;
                    std::cout << leter << " ";
                }
                std::cout << std::endl;
            }
            std::cout << i+1 << " ";
            for (int j=0; j<y; j++) {
                switch (board[i][j]) {
                    case 2:
                        std::cout << "X ";
                        break;
                    case 3:
                        std::cout << "+ ";
                        break;
                    default:
                        std::cout << "# ";
                }
            }
            std::cout << std::endl;
        }
        if (objective!=0) {
            std::cout << "Esta a " << objective << " barcos de ganar!" << std::endl;
        }
        attemps++;
    }
    while (objective>0);
    std::cout << "Felicidades! usted ha ganado en " << attemps << " intentos\n";
    return 0;
}