#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;


double Distance(int x1 ,int x2, int y1 , int y2)
{
    return (double)(pow(x1-x2,2) + pow(y1-y2,2));
}

int solution()
{
    vector<pair<int , int>> SIndex;
    map<char , vector<pair<int,int>>> keyboard;

    int nRow , nCol , maxDistance , inputLen ;
    long long ans = 0;
    string input;

    cin >> nRow >> nCol >> maxDistance;

    for(int i = 0 ; i < nRow ; i++){
        for(int j = 0 ; j < nCol ; j++){
            char c;
            cin >> c;
            if(c == 'S')
                SIndex.push_back(make_pair(i,j));
            else{
                std::map<char , vector<pair<int,int>>>::iterator itt = keyboard.find(c);
                //vector<pair<int,int>> v ;
                if(itt != keyboard.end()){
                    (itt->second).push_back(make_pair(i,j));
                }
                else
                {
                    vector<pair<int,int>> v ;
                     v.push_back(make_pair(i,j));
                    keyboard.insert(pair<char,vector<pair<int,int>>>(c, v));
                }
                //v.push_back(make_pair(i,j));
                //keyboard.insert(pair<char,vector<pair<int,int>>>(c, v));
            }
        }
    }

    cin >> inputLen >> input;

    for(int i = 0 ; i < inputLen ; i++)
    {
        char c = input[i];
        char smallC = c - 'A' + 'a';
        std::map<char , vector<pair<int,int>>>::iterator it , it2;

        it = keyboard.find(c);
        it2 = keyboard.find(smallC);

        if(c >= 'A' && c <= 'Z')
        {
           if(it2 == keyboard.end() || SIndex.size()==0)
           {
               return -1;
           }

            vector<pair<int , int>> indxesC = it2->second;

            bool written = false;

            for(pair<int , int> indx : SIndex)// loop over all shifts
            {
                for(pair<int , int> indxC : indxesC) // loop over all chars = c
                {
                   double dist = Distance(indx.first , indxC.first , indx.second , indxC.second);

                   if(dist <= (double)pow(maxDistance,2))
                   {
                       written = true;
                       break;
                   }
                }
                if(written) break;
            }

            if(!written){
              //  cout << input[i] << " ";
                ans++;
            }
        }
        else
        {
            if (it == keyboard.end())
                return -1;
        }
    }

    return ans;
}

int main()
{
    cout <<solution()<< endl;
    return 0;
}

