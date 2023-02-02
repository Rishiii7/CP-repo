#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem :
Sort array using Selection sort.

Noote :- Best when using lesser memmory space 
         and is not stable algorithm.

Time Complexity :- theta(n^2)
Aux Space Complexity :- O(1)
*/


vector<int> SelectionSort( vector <int> arr)
{
    /*
    Args : 
    arr : Integer array
    
    Variables:
    n : Integer -- size of array
    min_ind : Integer -- storing index of smallest element
    
    Returns :
    Integer array
    */
    int n = arr.size();
    int min_ind;
    for (int i = 0; i < n-1; i++)
    {
        min_ind = i;

        for (int j = i+1; j < n ; j++)
        {
            if(arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }

        swap(arr[i] , arr[min_ind]);
    }
    
    return arr;
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

    //Selection sort
    arr = SelectionSort(arr);
    cout<<"Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}