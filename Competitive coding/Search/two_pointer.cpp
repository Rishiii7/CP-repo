#include <iostream>
#include <vector>
using namespace std;

/*
Problem :
Find wether their is pair for given sum is present or not

Note :- Array is sorted !!

solution :
if sum of pair if greater than the given sum then,
decrease the higher value in the pair. If less then,
increase  the lower value in the pair.

Time Complexity :- O(n)
Aux Space Complexity :- O(1)
*/

bool isPair_TwoPointer(vector <int> arr, int sum)
{
    /*
    Params :
    arr : Integer Vector -- array
    sum : Integer

    Variables :
    n : Integer -- size of array
    i,j : Integer -- Indices of array
    
    Return : Boolean
    */
    int n = arr.size();
    int i = 0, j = n-1;

    
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

int main()
{
    int n,ele,sum;
    vector <int> arr;

    cout<<"Enter the size of array : ";
    cin>>n;

    cout<<"Enter the elements : ";
    for(int i = 0  ; i < n ; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Enter the sum : ";
    cin>>sum;

    if(isPair_TwoPointer(arr,sum))
    {
        cout<<"Pair is present "<<endl;
    }
    else
    {
        cout<<"Pair is not present "<<endl;
    }
}