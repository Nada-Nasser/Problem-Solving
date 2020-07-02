#include <iostream>
#include <string>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int sum1 = 0 , sum2 = 0 , diff = 0 ,nQ = 0 , nComp = 0 , nCorrect = 0;
    string s1 ,s2;
    cin >> s1 >> s2;

    for(int i = 0 ; i < s1.size() ; i++)
    {
        if(s1[i] == '+') sum1++;
        else sum1--;

        if(s2[i] == '+') sum2++;
        else if (s2[i] == '-')sum2--;
        else nQ++;
    }
    diff = sum1 - sum2;

    if(diff == 0 && nQ==0){
        cout << (double)1 ;
        return 0;
    }
    else if(diff!= 0 && nQ==0){
        cout << (double)0 ;
        return 0;
    }

    nComp = pow(2,nQ);
    nCorrect = 0;

    for(int i = 0 ; i < nComp ; i++)
    {
        std::string binary = std::bitset<10>(i).to_string(); //to binary
        int nOnes =  (std::count(binary.begin(), binary.end(), '1'));
        int nZero =  (binary.size() - nOnes - (10-nQ));
        int value = (nOnes) - (nZero);
        if(diff == value)
            nCorrect++;
    }

    cout << std::setprecision(20) << ((double)nCorrect/nComp);


    return 0;
}
