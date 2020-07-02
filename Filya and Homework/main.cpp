#include <iostream>
#include <algorithm>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

int main()
{
    FastIO;

    ll n , num;
    vector<ll> Numbers;
    bool isValid = true;

    cin >> n;
    for(ll i = 0 ; i < n ; i++){
        cin >> num;
        if(Numbers.size() < 4)
        {
            vector<ll>::iterator it = find(Numbers.begin(),Numbers.end(),num);
            if(it == Numbers.end())
                Numbers.push_back(num);
        }
    }

    if(Numbers.size()<=2)
    {
        cout << "YES";
        return 0;
    }
    else if(Numbers.size() >= 4)
    {
        cout << "NO";
        return 0;
    }

    sort(Numbers.begin(),Numbers.end());

    int diff1 = Numbers[1] - Numbers[0], diff2 = Numbers[2] - Numbers[1];

    if(diff2 == diff1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

