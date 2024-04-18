#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int player = 1;
int choice;
char mark;

void drawBoard() {
    cout << "  Крестики-нолики" << endl;
    cout << "-------------------" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------" << endl;
}

void getPlayerChoice() {
    if (player == 1) {
        cout << "Ходит игрок 1 (X). Выберите номер клетки: ";
    }
    else {
        cout << "Ходит игрок 2 (O). Выберите номер клетки: ";
    }
    cin >> choice;

    mark = (player == 1) ? 'X' : 'O';

    switch (choice) {
    case 1:
        if (board[0][0] == '1')
            board[0][0] = mark;
        break;
    case 2:
        if (board[0][1] == '2')
            board[0][1] = mark;
        break;
    case 3:
        if (board[0][2] == '3')
            board[0][2] = mark;
        break;
    case 4:
        if (board[1][0] == '4')
            board[1][0] = mark;
        break;
    case 5:
        if (board[1][1] == '5')
            board[1][1] = mark;
        break;
    case 6:
        if (board[1][2] == '6')
            board[1][2] = mark;
        break;
    case 7:
        if (board[2][0] == '7')
            board[2][0] = mark;
        break;
    case 8:
        if (board[2][1] == '8')
            board[2][1] = mark;
        break;
    case 9:
        if (board[2][2] == '9')
            board[2][2] = mark;
        break;
    default:
        cout << "Недопустимый ход. Попробуйте снова." << endl;
        getPlayerChoice();
        break;
    }
}

int checkForWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
        board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
        board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
        return 0;
    return -1;
}

int main() {
    setlocale(LC_ALL, "ru");
    int gameStatus;
    do {
        drawBoard();
        getPlayerChoice();
        gameStatus = checkForWin();
        player = (player == 1) ? 2 : 1;
    } while (gameStatus == -1);

    drawBoard();

    if (gameStatus == 1) {
        cout << "**Игрок " << ((player == 1) ? 2 : 1) << " победил!**" << endl;
    }
    else {
        cout << "**Ничья!**" << endl;
    }

    return 0;
}
