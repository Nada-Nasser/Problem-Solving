#include <iostream>
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

using namespace std;

int main()
{
    FastIO;
    ll vp,vd,t,f,c , ans = 0;
    cin >> vp >> vd >> t >> f >> c;
    double CurrentP = vp*t;

    if(vd <= vp || CurrentP >= c){
        cout << 0;
        return 0;
    }

    double r = (double)vd/vp;
    while(true)
    {
        double point = (r*CurrentP)/(r-1);
        if(point >= c)
            break;
        ans++;
        double dur = (point/(double)vd) + f;
        CurrentP = point + (vp*dur);
    }
    cout <<  ans;
    return 0;
}



