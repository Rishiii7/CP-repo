#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Problem :
Sort the array using Bubble Sort

Solution:
1.  if next element is greater than the current element then swap,
    this ensures the largest element is placed at the end of array.
2.  To optimize the algorithm add bool variable to check if any
    element is swapped or not. (i.e line 37)
3.  if not then array is already sorted and we will break the loop. (i.e line 44)

Time Complexity :- O(n^2)
Aux Space Complexity :- O(1)
*/

vector<int> BubbleSort(vector <int> arr)
{
    /*
    Args :
    arr : Integer Vector -- of size n
    
    Variable :
    n : Integer -- size of array
    swapped : Boolean -- checking if elements are swapped or not
    
    Return : 
    sorted array
    */
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n-i-1; j++) // careful of (n-i-1)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
           break;
        }
        
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

    // implementing bubble sort
    arr = BubbleSort(arr);
    cout<<"Sorted array is : ";
    for(int i = 0 ; i<n ;i++)
    {
        cout << arr[i] <<" ";
    }
}