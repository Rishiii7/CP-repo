#include <iostream>
#include <vector>
using namespace std;

/*
Prblem : 
the problem is taking an unsorted array and counting the inversions in it. 
There are two conditions for the  elements to be inverse:
1. arr[i] > arr[j]
2. i < j

Time complexity :- O(nlogn)
Aux Space complexity :- O(n)
*/

int CountInverseMerge(vector <int> &arr , int l , int m , int r)
{
    /*
    Args ::
    arr : Integer array
    l,m,r : Integer -- indices of starting, middle and ending elements resp
    
    Paramters ::
    left,right : Integer vector
    n1, n2 : Integer -- sizes of left and right integer vector
    i,j,k : Integer -- indices of left, right, arr arrays
    res : Integer -- storing of the inverse count 
    
    Return :: Integer
    */
    int n1 = m-l+1;
    int n2 = r-m;
    vector <int> left;
    vector <int> right;
    int res = 0;

    // copying left and rght array
    for (int i = 0; i < n1; i++)
    {
        left.push_back(arr[l+i]);
    }
    for (int i = 0; i < n2; i++)
    {
        right.push_back(arr[m+1+i]);
    }

    // merging into original array with sorting
    int i = 0 , j = 0 , k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            res += (n1 - i);
        }
        k ++ ;
    }
    
    // merge remaining elements
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    
    return res;
}

int CountInversion(vector <int> &arr, int l, int r )
{
    /*
    Args ::
    arr : Integer array
    l,r : Integer -- indices of starting and ending elements resp

    Paramaters ::
    res : Integer -- storing of the inverse count
    m : Integer -- index of middle element of arr array

    Return :: Integer
    */
    int res = 0;
    if (l < r)
    {
        int m = l + (r-l)/2;
        res += CountInversion(arr , l , m);
        res += CountInversion(arr , m+1 , r);
        res += CountInverseMerge(arr , l , m , r);
    }
    
    return res;
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

    // computing inverse
    cout<<"No of Inverse in array is : "<<CountInversion(arr,0,n-1);
}