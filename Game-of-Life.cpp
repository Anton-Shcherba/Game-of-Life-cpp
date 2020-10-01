﻿#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //СТРУКТУРА КЛЕТКИ
    struct cell {
        bool live; //состояние
        unsigned neighbors; //соседи
    };

    cell field[102][102]; //макс.100х100 + рамка из нулей
    for (int m = 0; m < 102; m++) for (int n = 0; n < 102; n++) {
        field[m][n].live = false;
        field[m][n].neighbors = 0;
    }

    //ЧТЕНИЕ
    int M, N;
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

    //РАСЧЁТ СОСЕДЕЙ
    for (int m = 1; m <= M; m++) for (int n = 1; n <= N; n++) {
        unsigned tmp = 0;
        if (field[m - 1][n - 1].live) tmp++;
        if (field[m - 1][n].live) tmp++;
        if (field[m - 1][n + 1].live) tmp++;
        if (field[m][n - 1].live) tmp++;
        if (field[m][n + 1].live) tmp++;
        if (field[m + 1][n - 1].live) tmp++;
        if (field[m + 1][n].live) tmp++;
        if (field[m + 1][n + 1].live) tmp++;
        field[m][n].neighbors = tmp;
    }
}
