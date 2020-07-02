#include <iostream>

using namespace std;
char input[4][4];

bool isPassed(int i , int j)
{
    char color = input[i][j]; int diff = 0;

    if(input[i][j+1]  != color){diff++;}
    if(input[i+1][j]  != color){diff++;}
    if(input[i+1][j+1]!= color) {diff++;}

    if(diff <= 1 || diff == 3)
        return true;
    else
        return false;
}

int main()
{
    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < 4 ; j++)
            cin >> input[i][j];
    if(isPassed(0,0)||isPassed(0,1)||isPassed(0,2)||
       isPassed(1,0)||isPassed(1,1)||isPassed(1,2)||
       isPassed(2,0)||isPassed(2,1)||isPassed(2,2))
    {
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}
