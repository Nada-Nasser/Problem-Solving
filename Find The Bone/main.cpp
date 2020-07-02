#include <iostream>

using namespace std;

int holes[1000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n , m , k , bonePos = 1;
    cin >> n >> m >> k;

    for(int i = 0 ; i < m ; i++)
    {
        int h;
        cin >> h;
        holes[h] = -1;
    }

    for(int i = 0 ; i < k ; i++)
    {
        int u,v;
        cin >> u >> v;

        if(holes[bonePos] == -1) continue;

        if(u == bonePos)
            bonePos = v;
        else if(v == bonePos)
            bonePos = u;
    }

    cout << bonePos;

    return 0;
}
