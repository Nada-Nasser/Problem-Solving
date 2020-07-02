#include <iostream>
#include <vector>
#include <algorithm>

#define INT long long
#define MAXN 100000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    INT n , arr[MAXN];
    cin >> n;

    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    sort(arr , arr+n);

    for(int i= 1 ; i < n-1 ; i++)
    {
        if(arr[i]+arr[i-1] > arr[i+1])
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
