#include <iostream>

#define INT long long

using namespace std;

INT sumDigits(INT n)
{
    INT sum = 0, d=0;
    while(n > 0)
    {
        d = n%10;
        n/=10;
        sum +=d;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    INT n=0 , ans = 0;
    string tempNumber;

    cin>>tempNumber;

    for(INT i=0;i<tempNumber.size();i++)
        n+=(INT)(tempNumber[i]-'0');

    if(tempNumber.size() > 1)
        ans++;

    while(n > 9)
    {
        ans++;
        n = sumDigits(n);
    }

    cout << ans;

    return 0;
}
