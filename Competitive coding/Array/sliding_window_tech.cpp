#include <iostream>
#include <vector>
using namespace std;

/*
Problem :
Find the maximum sum of K sub array

Time Complexity :- O(n)
Aux Space Complexity :- O(1)
*/

int SlidingWindowTechnique(vector <int> arr, int k = 1)
{
    /*
    Params:
    arr : Integer Vector
    k : Integer -- size of window

    Returns:
    Integer

    Variable :
    n : Integer -- size of array
    sum : Integer -- sum of k sub array
    maxi : Integer -- maximum of the sum of k sub array
    */
    int n = arr.size();
    int sum = 0;
    int maxi;

    //finding the first k sub array
    for(int i = 0 ; i < k ; i++)
    {
        sum += arr[i];
    }
    maxi = sum;

    //adding k+1th element and substracting first element
    // of previous subarray
    for(int i = k ; i < n ; i++)
    {
        sum = sum + arr[i] - arr[i-k];
        maxi = max(maxi , sum);
    }

    return maxi;
}

int main()
{
    //initialize
    vector <int> arr;
    int n,ele;
    int k;

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

    //enter window size
    cout<<"Enter the window size : ";
    cin>>k;
    
    //calling function
    cout<<"Maximum sum of given window is : "<< SlidingWindowTechnique(arr , k);
    
}