#include <iostream>
#include <vector>
using namespace std;

/*
Problem :
Find Median of the two array

Time Complexity :- O(n)
Aux Space Complexity :- O(n+m)*/


int Median(vector <int> arr1, vector<int> arr2)
{
    /*
    Params : 
    arr1, arr2 : Integer Vector
    
    Variable :
    res_arr : Integer Vector
    min_len : Integer -- minimum size of array 
    res_i, arr1_i,arr2_i : Integer -- indices of array
    
    Returns : Integer
    */
    vector <int> res_arr;
    int min_len = min(arr1.size(), arr2.size());
    int res_i = 0, arr1_i = 0, arr2_i = 0;

    // Combining two arrays
    while (res_i < min_len)
    {
        if (arr1[arr1_i] < arr2[arr2_i])
        {
            res_arr.push_back(arr1[arr1_i]);
            arr1_i ++;
        }
        else
        {
            res_arr.push_back(arr2[arr2_i]);
            arr2_i ++;
        }

        res_i ++;
    }

    // if size of arr1 is more than adding element to new array
    while (arr1_i < arr1.size())
    {
        res_arr.push_back(arr1[arr1_i]);
        arr1_i ++;
    }

    // if size of arr1 is more than adding element to new array
    while (arr2_i < arr2.size())
    {
        res_arr.push_back(arr2[arr2_i]);
        arr2_i ++;
    }

    /*
    for printing the array
    for(int i = 0 ; i < res_arr.size() ; i++)
    {
        cout<<res_arr[i]<<" ";
    }
    cout<<endl;
    */

    if (res_arr.size() % 2 == 1)
    {
        return (double)res_arr[res_arr.size() / 2];
    }
    else
    {
        return ((double)(res_arr[res_arr.size() / 2] + res_arr[ (res_arr.size() / 2) - 1])) / (double)2;
    }

}


int main() 
{
    //initialize
    vector <int> arr1, arr2;
    int n,ele;
    int x;

    //size of array;
    cout<<"Enter size of 1st array : ";
    cin>>n;

    //elements of array
    cout<<"Enter elements if aray : ";
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        arr1.push_back(ele);
    }

    //size of array;
    cout<<"Enter size of 2nd array : ";
    cin>>n;

    //elements of array
    cout<<"Enter elements if aray : ";
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        arr2.push_back(ele);
    }
    
    // median
    cout<<"Median is : "<<Median(arr1, arr2);
}