#include <iostream>

using namespace std;

int main()
{
    int n,k,l,r,p=0;

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> l >>r;
        p+= (r-l+1);
    }
    cout << (k-(p%k))%k;

    return 0;
}
