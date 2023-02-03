#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem :
Sort the array using Insertion Sort

Idea :
for every i-th element find the index
in the sorted array.
1st element is always sorted.

Time complexity :- O(n^2)
Aux Space Complexity :- O(1)
*/


void InsertionSort(vector<int> &arr)
{
    /*
    Args :
    arr : Integer array
    
    Variables :
    n : Integer -- size of array
    key : Integer -- storing ith element
    j : Integer -- index
    */
    int n = arr.size();
    int key;
    int j;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }
    
}


int main()
{
    // Initialization
    int n, ele;
    vector <int> arr;

    // Siz e of vector
    cout<<"Enter size of array : ";
    cin>>n;

    // Array storing
    cout<<"Enter elements : ";
    for(int i = 0 ; i < n ; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }

    //Insertion sort
    InsertionSort(arr);
    cout<<"Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}