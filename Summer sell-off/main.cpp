#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n , f , l[100000], k[100000];
    vector<pair< long long, long long>> MaxIndex;

    cin >> n >> f;
    for( long long i = 0 ; i < n ; i ++)
    {
        cin >> k[i] >> l[i];
        MaxIndex.push_back(make_pair((min(2*k[i],l[i]) - min(k[i],l[i])),i));
    }

    sort(MaxIndex.rbegin(),MaxIndex.rend());
    long long ans = 0;
    for( long long i = 0 ; i < f ; i++)
    {
         long long index = MaxIndex[i].second;
        ans+= min(2*k[index],l[index]);
    }

    for( long long i = f ; i < n ; i++)
    {
         long long index = MaxIndex[i].second;
        ans+= min(k[index],l[index]);
    }

    cout << ans;

    return 0;
}
