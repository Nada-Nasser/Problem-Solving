#include <iostream>

#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

using namespace std;

int main()
{
    FastIO;
    ll ans = 0 , nOpenBracket = 0 , wrongBracket = 0;
    string input;
    cin >> input;

    for(ll i = 0 ; i < input.size() ; i++)
    {
        if( input[i] == '(') // open Bracket
            nOpenBracket++;
        else // close Bracket
            if(nOpenBracket > 0)
                nOpenBracket--;
            else // wrong Bracket
                wrongBracket++;
    }
    wrongBracket+= nOpenBracket;

    ans = input.size() - wrongBracket;
    cout << ans;

    return 0;
}
