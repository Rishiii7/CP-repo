#include <iostream>
#include<vector>
using namespace std;

/*
Problem : 
find the Length of longest even odd subarray

Note : 
if statements staring from line to line can be writeen as
if( (arr[i] %2 == 0 && arr[i+1] %2 == 1) || (arr[i] %2 == 1 && arr[i+1] %2 == 0) )
{
    len ++;
    max_len = max(max_len, len);  
}
else
{
    len = 1;
}

Time complexity :- O(n)
Aux Space Complexity :- O(1)
*/

int LongestEvenOddSubarray(vector <int> arr)
{
    /*
    Params : 
    arr : Integer Vector
    
    Returns : Integer
    
    Variables : 
    max_len, len : Integer -- containing max length of array
    n : Integer -- size of array
    */
    int max_len = 1;
    int len = 1;
    int n = arr.size();

    for(int i = 0 ; i < n-1 ; i++)
    {
        // if i-th element is even
        if( arr[i] % 2 == 0)
        {
            // if i+1-th element is odd
            if( arr[i+1] % 2 == 1 )
            {
                len ++;
                max_len = max(max_len, len);
            }
            else
            {
                len = 1;
            }
        }
        // if i-th element is odd
        else
        {
            //if i+1-th element is even
            if( arr[i+1] % 2 == 0 )
            {
                len ++;
                max_len = max(max_len, len);
            }
            else
            {
                len = 1;
            }
        }
    }

    return max_len;
}

int main()
{
    //initialize
    vector <int> arr;
    int n,ele;

    //size of array;
    cout<<"Enter size of array : ";
    cin>>n;

    //elements of array
    cout<<"Enter elements if aray : ";
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Length of longest even odd subarray is : "<<LongestEvenOddSubarray(arr);
}