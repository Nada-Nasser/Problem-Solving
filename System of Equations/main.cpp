#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n , m , MIN , MAX , ans = 0;
    cin >> n >> m;
    MIN = min(n,m);
    MAX = max(n,m);

    for(int A = 0 ; A <= MIN ; A++)
    {
        int B = MAX - pow(A,2);
        if(B >=0 && A + pow(B,2) == MIN)
            ans++;
    }
    cout << ans;

    return 0;
}
