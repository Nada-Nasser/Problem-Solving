#include <iostream>
#include <vector>
#include <algorithm>
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define p pair<ll,ll>
#define for(i,n) for(ll i = 0 ; i < n ; i++)

using namespace std;

int main()
{
    FastIO;
    ll n , a,b;
    vector<p> laptops; // price , quality
    vector<ll> quality;

    cin >> n;
    for(i,n){
        cin >> a >>b;
        laptops.push_back(p(a,b));
    }

    sort(laptops.begin(),laptops.end());

    for(i,n)
        quality.push_back(laptops[i].second);

    if(!is_sorted(quality.begin(),quality.end()))
        cout << "Happy Alex";
    else
        cout << "Poor Alex";

    return 0;
}
