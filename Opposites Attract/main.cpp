#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int main()
{
    long long n , nZeros , ans = 0;
    map<long long,pair<long long,long long>> couples ; // + , -
    cin >> n;
    long long client = 0;
    nZeros = 0;
    for(long long i = 0 ; i < n ; i++)
    {
        cin >> client;
        std::map<long long,pair<long long,long long>>::iterator it = couples.find(abs(client));
        if(client == 0)
        {
            nZeros++;
        }
        else if(client > 0) // +
        {
            if(it != couples.end())
                (it->second).first++;
            else
                couples.insert(pair<long long , pair<long long,long long>>(abs(client) , make_pair(1,0)));
        }
        else // -
        {
            if(it != couples.end())
                (it->second).second++;
            else
                couples.insert(pair<long long , pair<long long,long long>>(abs(client) , make_pair(0,1)));
        }
    }

   // cout << "START\n";
    for (std::map<long long,pair<long long,long long>>::iterator it=couples.begin(); it!=couples.end(); ++it)
    {
     //   cout << it->first << " " << (it->second).first <<  "  " << (it->second).second << endl;
        ans+= (((it->second).first) * ((it->second).second));
    }

    ans += (nZeros*(nZeros-1))/2;

    cout << ans;

    return 0;
}
