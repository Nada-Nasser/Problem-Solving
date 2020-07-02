#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n , k;
    cin >> n >> k;

    int start = 1 , End = n , last = start;
    for(int i = 0 ; i < k ; i++)
    {
        if(i%2 == 0)
        {
            cout << start++ << " ";
            last = start;
        }
        else{
            cout << End-- << " ";
            last = End;
        }
    }
    int s = 1;
    if(last == End)
        s*=-1;

    for(int i = k ; i < n ; i++)
    {
        cout << last << " ";
        last+=s;
    }
    return 0;
}
/*
    for(int i = k ; i< n ; i++)
    {
        prev--;
        ans.push_back(prev);
    }

    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;

    cout << 1 << " ";
    ans.push_back(1);
    int kIndex = 0 , z = 1;
    for(int i = 1 ; i < n ; i++ , kIndex++)
    {
        if(kIndex >= k) kIndex = 0;

        int y = diff[kIndex];
        int x;

        if(y >= z)
            x = z+y;
        else{
            x = abs(z-y);

            vector<int>::iterator it = find(ans.begin(), ans.end(), x);

            if (it != ans.end()){
                    x = z+y;
            }
        }
        z = x;
        ans.push_back(x);
        cout << x << " ";
    }
// 1 10 2 9 8 7 6 5 4 3
*/
