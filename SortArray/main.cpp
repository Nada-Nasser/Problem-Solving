#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void Reverse(int s , int e , int *arr , int n)
{
    int r = e;
    int i = s;
    while(i<r)
    {
   //     cout <<arr[i] << arr[r] << endl;
        swap(arr[i],arr[r]);
        i++;
        r--;
    }
}

bool isSorted(int *arr ,int n)
{
    for(int i = 0 ; i < n ; i++ )
    {
        if(i>0 && !(arr[i]>arr[i-1]))
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n , arr[100000] , X , Y;
    bool findX = false , findY = false;

    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    for(int i = 0; i < n ; i++)
    {
        if(i==0 && !findX && arr[i+1] < arr[i])
        {
            X = i;
            findX = true;
          //  cout << "1- " << i << endl;
           // cout << arr[i+1] << " < " << arr[i] << endl;
        }

        else if(i>0 && arr[i-1] > arr[i] && !findX)
        {
            X = i-1;
            findX = true;
                       // cout << "2- " << i << endl;
        }

        else if(findX && i>0 && arr[i-1] < arr[i] && !findY)
        {
            Y = i-1;
            findY = true;
                       // cout << "3- " << i << endl;
        }

        else if(!findY && i == n-1 && findX)
        {
            Y = i;
            findY = true;
                        //cout << "4- " << i << endl;
        }
    }

    if(!findX && !findY)
    {
        cout<<"yes"<<endl;
        cout << 1 << " " << 1;
        return 0;
    }
   // cout << X << " " << Y << endl;
    Reverse(X , Y , arr , n);

//    for(int i = 0 ; i < n ; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
    if(isSorted(arr , n))
    {
        cout << "yes"<<endl;
        cout << X+1 << " " << Y+1;
    }
    else
    {
        cout << "no";
    }

    return 0;
}


/*
5
69 37 27 4 2
*/
