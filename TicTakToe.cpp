#include <iostream>

using namespace std;

    int row, column;
    int n1, n2;
    char token = 'x';
    bool tie = false;
    char space[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'} };
    void FuncOne(){
    cout << "    |     |    \n";
    cout <<"  " << space[0][0] << " |  " << space[0][1] << "  |  " << space[0][2] << "\n";
    cout << "____|_____|____\n";
    cout << "    |     |    \n";
    cout << "  " << space[1][0] << " |  " << space[1][1] << "  |  " << space[1][2] << "\n";
    cout << "____|_____|____\n";
    cout << "    |     |    \n";
    cout << "  " << space[2][0] << " |  " << space[2][1] << "  |  " << space[2][2] << "\n";
    cout << "    |     |    \n";


}
void FuncTwo() {
    int digit;
    if (token == 'x') {
        cout << n1 << "please enter";
        cin >> digit;
    }
    if (token == '0') {
        cout << n2 << "please enter";
        cin >> digit;
    }
    switch (digit)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;

    default:
        break;
    }
    if (digit<1 || digit>9)
    {
        cout << "Invali ebaniy\n";
    }
    if (token == 'x' && space[row][column] != 'x' && space[row][column] !='0')
    {
        space[row][column]='x';
        token = '0';
    }
    else if (token == '0' && space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = '0';
        token = 'x';
    }
    else
    {
        cout << "Pososi!!!";
        FuncTwo();
    }
    FuncOne();
}

bool FuncThree() {
    for (int i = 0; i < 3; i++)
    {

    }
}

int main() {
    FuncOne();
    FuncTwo();
}

