#include <iostream>

#include "globals.h"
#include "History.h"
#include "Rabbit.h"

History::History(int nRows, int nCols) : rowPMV(nRows), colPMV(nCols){
    for (int i = 0; i < MAXROWS;i++){
        for (int j = 0; j < MAXCOLS;++j){
            Grid[i][j] = 0;
        }
    }
}

bool History::record(int r, int c){
        
    if (r <= MAXROWS && c <= MAXCOLS){
        Grid[r-1][c-1]++; // increment the point in the grid by one
        return true;
    }
    else return false;
}

void History::display() const{
    clearScreen();
    
    for (int i = 0; i < rowPMV; i++){
        for (int j = 0; j < colPMV;j++){
            switch (Grid[i][j]){
                case 1:
                    std::cout << "A";
                    break;
                case 2:
                    std::cout << "B";
                    break;
                case 3:
                    std::cout << "C";
                    break;
                case 4:
                    std::cout << "D";
                    break;
                case 5:
                    std::cout << "E";
                    break;
                case 6:
                    std::cout << "F";
                    break;
                case 7:
                    std::cout << "G";
                    break;
                case 8:
                    std::cout << "H";
                    break;
                case 9:
                    std::cout << "I";
                    break;
                case 10:
                    std::cout << "J";
                    break;
                case 11:
                    std::cout << "K";
                    break;
                case 12:
                    std::cout << "L";
                    break;
                case 13:
                    std::cout << "M";
                    break;
                case 14:
                    std::cout << "N";
                    break;
                case 15:
                    std::cout << "O";
                    break;
                case 16:
                    std::cout << "P";
                    break;
                case 17:
                    std::cout << "Q";
                    break;
                case 18:
                    std::cout << "R";
                    break;
                case 19:
                    std::cout << "S";
                    break;
                case 20:
                    std::cout << "T";
                    break;
                case 21:
                    std::cout << "U";
                    break;
                case 22:
                    std::cout << "V";
                    break;
                case 23:
                    std::cout << "W";
                    break;
                case 24:
                    std::cout << "X";
                    break;
                case 25:
                    std::cout << "Y";
                    break;
                case 26:
                    std::cout << "Z";
                    break;
                default:
                    std::cout << ".";
                    break;
            }
        }
        std::cout << '\n'; //format it so that it goes to next line when finished a row of columns
    }
    
    std::cout << '\n';
}

