#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m , ans=0;
    cin >> n >> m;
    vector<set<int>> students(n+1);

    for(int i = 0 ; i < m ; i++)
    {
        int x,y;
        cin >> x >> y;
        students[x].insert(y);
        students[y].insert(x);
    }

    while(true)
    {
        vector<int> Group;

        for(int i = 1 ; i <= n ; i++)
            if(students[i].size() == 1)
                Group.push_back(i);

        if(Group.size()==0) break;
        else ans++;

        for(int i = 0 ; i < Group.size() ; i++)
        {
            set<int>::iterator it = students[Group[i]].begin();
            students[Group[i]].clear();
            students[*it].erase(Group[i]);
        }
    }

    cout << ans;

    return 0;
}
