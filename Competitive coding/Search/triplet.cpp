#include <iostream>
#include <vector>
using namespace std;

/*
Problem :
Find a triplet such that its sum is equal to the given sum

Solution :
sustract ele from the given sum then
use two_pointer approach

Time complexity :- O(n^2)
Aux Space Comlexity :- O(1)
*/

bool isPair_TwoPointer(vector <int> arr, int sum, int ind)
{
    /*
    Params :
    arr : Integer Vector -- array
    sum : Integer
    ind  : Integer -- index of array

    Variables :
    n : Integer -- size of array
    i,j : Integer -- Indices of array
    
    Return : Boolean
    */
    int n = arr.size();
    int i = ind, j = n-1;

    
    while (i < j)
    {
        if (arr[i] + arr[j] == sum)
        {
            return true;
        }
        else if (arr[i] + arr[j] > sum)
        {
            j --;
        }
        else
        {
            i ++;
        }
    }

    return false;
}

bool Triplet_TwoPointer(vector <int> arr, int sum)
{
    /*
    params :
    arr : Integer Vector -- array
    sum : Integer

    Variable :
    n : Integer -- size of array
    new_sum : Integer -- storing new sum 

    Returns : Boolean
    */
    int n = arr.size();
    int new_sum;

    for(int i = 0 ; i < n ; i++)
    {
        new_sum = sum - arr[i];
        if (isPair_TwoPointer(arr, new_sum, i+1))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    //initialize
    vector <int> arr;
    int n,ele;
    int sum;

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
    
    //sum to be searched
    cout<<"Enter sum to be searched : ";
    cin>>sum;

    if (Triplet_TwoPointer(arr,sum))
    {
        cout<<"Triplet present "<<endl;
    }
    else
    {
        cout<<"Triplet not present "<<endl;
    }

}