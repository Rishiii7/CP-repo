#include<iostream>
#include <vector>

using namespace std;
/*
Problem : 
Frequencies in A Sorted Array

Solution :
1. check if next element is same or not
    1.1 if same increment the count
    1.2 print the count and reset it to 1
2. check if last element is same or not -- Corner Case
    2.1 if same print cout
    2.2 print 1

Time Complexity : theta(n)

Aux Space Complexity : O(1)
*/

void FrequencyOfSortedArray(vector <int> arr)
{
    /*
    Params 
    arr : Integer Vector
    
    Returns
    None
    
    Variables :
    count : Integer keeps count of element
    len : length of array
    */
    int count = 1;
    int len = arr.size();
    for(int i = 0; i < len - 1; i++)
    {
        if (arr[i] == arr[i+1])
        {
            count ++ ;
        }
        else
        {
            cout<<arr[i] << " : "<<count <<endl;
            count = 1;
        }
    }

    if (arr[len - 1] != arr[len - 2])
    {
        cout<<arr[len - 1]<<" : "<<"1";
    }
    else
    {
        cout<<arr[len - 1]<<" : "<<count;
    }
}

int main()
{
    //initialize
    vector <int> arr;
    int n,ele;

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

    //calling function
    cout<<"Frequencies of an sorted array are : ";
    FrequencyOfSortedArray(arr);
    
} 
