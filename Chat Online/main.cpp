#include <iostream>
#include <vector>
#include <algorithm>

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    fastIO;

    int p,q,l,r , ans = 0 , a,b;
    cin >> p >> q >> l >> r;
    vector<pair<int,int>> X , Z;

    for(int i = 0 ; i < p ; i++){
        cin >> a >> b;
        X.push_back(pair<int,int>(a,b));
    }
    for(int i = 0 ; i < q ; i++){
        cin >> a >> b;
        Z.push_back(pair<int,int>(a,b));
    }

    for(int t = l ; t <= r ; t++)
        for(int i = 0 ; i < q ; i++)
        {
            pair<int,int> ZTime = Z[i];
            for(int j = 0 ; j < p ; j++)
            {
                pair<int,int> XTime = X[j];
                if(XTime.first <= ZTime.second+t && XTime.second >= ZTime.first+t)
                {
                    ans++;
                    i = q + 1;
                    break;
                }
            }
        }
    cout << ans;

    return 0;
}
