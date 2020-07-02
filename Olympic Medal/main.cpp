#include <iostream>
#include <math.h>
#include <iomanip>

#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    FastIO;
    int n , m , k , MaxR1 = INT_MIN , MaxP1 = INT_MIN , MinP2 = INT_MAX , A,B;

    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int r;
        cin >> r;
        if(r > MaxR1)
            MaxR1 = r;
    }

    cin >> m;
    for(int i = 0 ; i < m ; i++)
    {
        int p1;
        cin >> p1;
        if(p1 > MaxP1)
            MaxP1 = p1;
    }

    cin >> k;
    for(int i = 0 ; i < k ; i++)
    {
        int p2;
        cin >> p2;
        if(p2 < MinP2)
            MinP2 = p2;
    }

    cin >> A >> B;

    double r2 = (double)sqrt((double)(pow(MaxR1,2))/(double)(1+((double)(A*(double)MinP2)/(B*(double)MaxP1))));

    cout << std::setprecision(15) << r2;

    return 0;
}
