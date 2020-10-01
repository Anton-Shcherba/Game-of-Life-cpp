#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <windows.h>

int main()
{
    //ПЕРЕМЕННЫЕ
    struct cell {
        bool live;
        unsigned neighbors;
    };

    cell field[102][102];
    for (int m = 0; m < 102; m++) for (int n = 0; n < 102; n++) {
        field[m][n].live = false;
        field[m][n].neighbors = 0;
    }

    int M, N;

    //ЧТЕНИЕ
    ifstream file("life.txt");
    file >> M >> N;

    file.get();
    for (int m = 1; m <= M; m++) {
        for (int n = 1; n <= N; n++) {
            int t = file.get();
            if (t != 10) field[m][n].live = t - 48;
        }
        file.get();
    }
    file.close();
}
