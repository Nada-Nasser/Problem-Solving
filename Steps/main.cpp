#include <iostream>

#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

using namespace std;

int main()
{
    FastIO;
    ll n,m,Xc,Yc,k , nSteps = 0 , dx,dy;

    cin >> n >> m >> Xc >> Yc >> k;

    for(ll i = 0 ; i < k ; i++)
    {
        cin >> dx >> dy;
        ll stepX = INT_MAX , stepY = INT_MAX;

        if(dx > 0) stepX = (n-Xc)/dx;
        else if (dx < 0) stepX = (1 - Xc)/dx;

        if(dy > 0) stepY = (m-Yc)/dy;
        else if(dy < 0) stepY = (1-Yc)/dy;

        ll newSteps = min(stepX,stepY);

        if(newSteps > 0 && newSteps!= INT_MAX)
        {
            Xc+= (newSteps*dx);
            Yc+= (newSteps*dy);
            nSteps+=newSteps;
        }
    }

    cout << nSteps;

    return 0;
}
