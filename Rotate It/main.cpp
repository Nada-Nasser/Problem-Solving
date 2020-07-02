#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

using namespace std;

ll arr[20020];

ll solution(ll n);
int main()
{
    FastIO;
    ll nTestCases , n;
    vector<int> ans;
    cin >> nTestCases;

    for(ll i = 0 ; i < nTestCases ; i++)
    {
        cin >> n;
        for(ll j = 0 ; j < n ; j++)
            cin >> arr[j];

        ans.push_back(solution(n));
    }
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i];
        if(i != ans.size()-1)
            cout << '\n';
    }

    return 0;
}

ll DzySum(ll start ,ll n)
{
    ll sum = 0;

    for(ll i = 0 ; i < n ; i++)
        if(i%2 == 0)
            sum+= arr[i+start];
    return sum;
}

ll solution(ll n)
{
    ll startIndex = 0 , Endindex = n-1 , MaxSum = INT_MIN ;
    for(ll i = 0 ; i < n ; i++) /// n Rotations
    {
        arr[Endindex + 1] = arr[startIndex];
        startIndex++;
        Endindex++;

        ll sum = DzySum(startIndex,n);
        MaxSum = max(sum , MaxSum);
    }
    return MaxSum;
}

