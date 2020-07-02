#include <iostream>
#include <set>

#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

using namespace std;

int main()
{
    FastIO;
    string input;
    ll ans = 0 , n , m;
    set<ll> Len;

    cin >> n >> m;

    for(ll i = 0 ; i < n ; i++)
    {
        cin >> input;
        if(ans != -1)
        {
            ll Gindex = input.find("G");
            ll Sindex = input.find("S");
            if(Sindex < Gindex) ans = -1;
            else
            {
                ll len = Sindex - Gindex + 1;
                Len.insert(len);
            }
        }
    }

    if(ans == -1) cout << -1;
    else          cout << Len.size();
    return 0;
}
