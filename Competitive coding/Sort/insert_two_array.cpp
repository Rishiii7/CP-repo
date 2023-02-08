#include <iostream>
#include <vector>
using namespace std;
/*
Problem : - print all the intersection of two sorted 
            array without repeating the element

Time complexity :- O(n) or O(m)
Aux space complexity :- O(1) 
*/

vector<int> InsertionOfTwoSortedArray(vector<int> arr1 , vector<int> arr2)
{
    /*
    Args : 
    arr1, arr2 : Integer vector
    
    Parameters : 
    n,m : Integer -- sizes of vector 1 & 2 resp
    i,j : Integer -- indices of vector 1 & 2 resp
    result : Integer vector -- storing of final output
    
    Returns : Integer array
    */
    int n = arr1.size();
    int m = arr2.size();
    int i = 0 , j= 0;
    vector <int> result;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j] )
        {
            // check for previous element to avoid duplication
            if (result.empty() || arr1[i - 1] != arr1[i])
            {
                result.push_back(arr1[i]);
            }
            i++;
            j++;
        }

        else if(arr1[i] < arr2[j])
        {
            i++;
        }

        else
        {
            j++;
        }
        
    }

    return result;
    
}

int main()
{
    // Initialization
    int n, ele;
    vector <int> arr1;
    vector <int> arr2;

    // Siz e of vector
    cout<<"Enter size of 1st array : ";
    cin>>n;

    // Array storing
    cout<<"Enter elements : ";
    for(int i = 0 ; i < n ; i++)
    {
        cin>>ele;
        arr1.push_back(ele);
    }

    // Siz e of vector
    cout<<"Enter size of 2nd array : ";
    cin>>n;

    // Array storing
    cout<<"Enter elements : ";
    for(int i = 0 ; i < n ; i++)
    {
        cin>>ele;
        arr2.push_back(ele);
    }

    // print the result
    cout<<"Intersection of Two array result is : ";
    vector <int> result  = InsertionOfTwoSortedArray(arr1, arr2);
    for (int i = 0; i < result.size() ; i++)
    {
        cout<<result[i]<<" ";
    }
    
}