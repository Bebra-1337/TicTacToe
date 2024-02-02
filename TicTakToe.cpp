#include <iostream>

using namespace std;

    int row, column;
    string n1, n2;
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
        cout << n1 << " please enter: ";
        cin >> digit;
    }
    if (token == '0') {
        cout << n2 << " please enter: ";
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
    
}

static bool FuncThree()
{
    for (int i = 0; i < 3; i++)
    {
        if (space[i][1] == space[i][0] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
        {
            return true;
        }
    }
        if (space[0][0]==space[1][1]&& space[1][1]==space[2][2]||space[0][2]==space[1][1]&&space[1][1]==space[2][0])
        {
            return true;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (space[i][j] !='x' && space[i][j] !='0')
                {
                    return false;
                }
            }
        }
        tie = true;
        return false;
}

int main() {
    cout << "Enter the first palyer name: \n";
    cin >> n1;
    cout << "Enter the second palyer name: \n";
    cin >> n2;
	while (!FuncThree())
	{
        FuncOne();
		FuncTwo();
        FuncThree();
	}
    if (token == 'x' && tie == false)
    {
        cout << n2 << " Wins!!!";
    }
    else if (token=='0' && tie==false)
    {
        cout << n1 << " Wins!!!";

    }
    else
    {
        cout << "It's Draw";
    }
}

