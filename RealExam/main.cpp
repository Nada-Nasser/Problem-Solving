
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <algorithm>

using namespace std;
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool isAnagram(string str1 , string str2);

///['bcd', 'abc']

int solution(vector<string> &A)
{
    vector<int> lens;

    for(int i = 0 ; i < A.size() ; i++)
    {
        string str = A[i];
        vector<string> anagram;
        anagram.push_back(str);

        for(int j = 0 ; j < A.size() ; j++)
        {
            string str2 = A[j];
            vector<string>::iterator it = A.begin()+j;

            if(isAnagram(str,str2) && i!=j)
            {
                anagram.push_back(str2);
                A.erase(it);
                j--;
            }
        }

        vector<string>::iterator it = A.begin()+i;
        A.erase(it);
        i--;
        lens.push_back(anagram.size());
        anagram.clear();
    }
    sort(lens.begin(),lens.end());

    int index = lens.size()-1;

    return lens[index];
}

void sortString(string &str)
{
   sort(str.begin(), str.end());
}

bool isAnagram(string str1 , string str2)
{
    if(str1.size() != str2.size())
        return false;
    sortString(str1);
    sortString(str2);

    for(int i = 0 ; i < str1.size() ; i++)
    {
        if(str1[i] != str2[i])
            return 0;
    }

    return 1;
}

// you can use includes, for example:
// #include <algorithm>
///[[1, 4, 3, 5], [3, 4]]

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int Search(int start , int End , vector<int> A, vector<int> B);
int helper(int start , int End , int startPlus ,int EndMinus , vector<int> A, vector<int> B);

int solution2(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    return helper(0 , A.size()-1 , 1 , A.size()-2 , A ,B);
}

int helper(int start , int End , int startPlus ,int EndMinus , vector<int> A, vector<int> B)
{
    if(EndMinus == start || startPlus == End)
        return A.size();

    int len1 = Search(start,startPlus,A,B);
    cout << start << " " << startPlus << " " << len1 << endl;

    int len2 = Search(EndMinus,End,A,B);

    cout << End << " " << EndMinus << " " << len2 << endl;

    if(len1!= -1 && len2 != -1)
        return min(len1,len2);
    else if(len1 != -1)
        return len1;
    else if(len2 != -1)
        return len2;
    else
        return helper(start , End , startPlus+1 , EndMinus-1, A,B);
}

int Search(int start , int End , vector<int> A, vector<int> B)
{
    for(int i = 0 ; i < B.size() ; i++)
    {
        bool flag = false;

        for(int j = start ; j <= End ; j++)
        {
            if(End == 2)
            cout << A[j] << " " << B[i] << endl;
            if(A[j] == B[i])
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            return -1;
        }
    }

    return End-start+1;
}


int main()
{
    ///[[1, 4, 3, 5], [3, 4]]
    vector<int> A = {1,4,3,5};
    vector<int> B = {4,3};

    vector<string> v = {"abc","cba","zxy","bca","yxz"};
    cout << solution(v);

    //cout << isAnagram("bcd","abc");
    return 0;
}
