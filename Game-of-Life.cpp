#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int moves; //количесто ходов
    cout << "Enter the number of moves: " << endl;
    cin >> moves;

    //СТРУКТУРА КЛЕТКИ
    struct cell {
        bool live; //состояние
        unsigned neighbors; //соседи
    };

    cell field[102][102]; //макс.100х100 + рамка из нулей
    for (int m = 0; m < 102; m++) for (int n = 0; n < 102; n++) { //заполнение матрицы нолями
        field[m][n].live = false;
        field[m][n].neighbors = 0;
    }

    //ЧТЕНИЕ
    int M, N;
    int living_cells = 0;
    ifstream file("life.txt");
    file >> M >> N;
    file.get();
    for (int m = 1; m <= M; m++) {
        for (int n = 1; n <= N; n++) {
            int t = file.get();
            if (t != 10) { //исключая перенос строки
                field[m][n].live = t - 48;
                living_cells += t - 48;
            }
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

    //ПЕРЕСЧЕТ(ПОДСЧЁТ) ЖИВЫХ КЛЕТОК 
    for (int m = 1; m <= M; m++) for (int n = 1; n <= N; n++) {
        if (field[m][n].live && field[m][n].neighbors != 2 && field[m][n].neighbors != 3) {
            living_cells--;
            field[m][n].live = false;
        }
        if (!field[m][n].live && field[m][n].neighbors == 3) {
            field[m][n].live = true;
            living_cells++;
        }
    }
    return 0;
}
