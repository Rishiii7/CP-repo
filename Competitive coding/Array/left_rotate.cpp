#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
Solution :
first reverse first k elements
then reverse remianing len-k elements
lastly reverse whole array

Time Complexity : O(n)
Aux Space Complexity : theta(1)
*/

void Reverse(vector<int> &arr, int start, int end)
{
    /*
    Params :
    arr : integer array
    start, end : Index of array
    
    Return : None
    
    Note : arr is passed by refrence
    */
    while(start < end)
    {
        swap(arr[start], arr[end]);
        start ++;
        end --;
    }
}

void LeftRotateBy_K_Places(vector <int> & arr, int k = 1)
{
    /*
    Params : 
    arr : Integer Array
    k : Integer to rotate an array
    
    Returns : None
    
    Variable :
    n : length of array
    */
    int n = arr.size();
    Reverse(arr, 0 , k - 1);
    Reverse(arr,k, n-1);
    Reverse(arr, 0 , n-1);
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

    //rotate input
    cout<<"enter a number to rotate an array : ";
    cin>>k;

    //calling left rotate function
    LeftRotateBy_K_Places(arr,k);
    //print the output
    cout<<"\n Array after rotating by k : ";
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i] << " ";
    }
}