#include<iostream>
#include <vector>
using namespace std;

/*
Problem :
To find max sum of subarray

Time Complexity :- O(n)
Aux Space Complexity :- O(1)
*/


int MaximumSumSubarray(vector <int> arr)
{
    /*
    Params :
    arr : Integer Vector

    Returns :
    Integer

    Variables :
    max_sum, max_prev : Integer -- storing max sum of subarray and 
                                   max sum of previous 0-ith array
    n : Integer -- size of array
    */
    int max_prev = arr[0];
    int max_sum = arr[0];
    int n = arr.size();

    for(int i = 1 ; i < n ; i++)
    {
        max_prev = max(max_prev + arr[i], arr[i]);
        max_sum = max(max_prev, max_sum);
    }

    return max_sum;
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

    cout<<"Maximum sum of subarray is : "<<MaximumSumSubarray(arr);
}