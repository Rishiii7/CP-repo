#include <iostream>
#include <vector>
using namespace std;
/*
Problem : 
Find count of maximum consecutive 1s in a binary array

Time Complexity :- thetha(n)
Aux Space Complexity :- O(1)
*/

int MaximumConsecutiveOnes(vector <int> arr)
{
    /*
    Params : 
    arr : Integer Vector
    
    Returns:
    Integer -- containing maximum frequency of consecutive 1's
    
    Variables :
    max_one : Integer -- storing maximum count of consecutive 1's
    count : Integer -- counting the no of consecutive 1's
    len : Integer -- size of array
    */
    int max_one = 0;
    int count = 0;
    int len = arr.size();
    for(int i = 0 ; i < len ; i++)
    {
        if (arr[i] == 1)
        {
            count ++;
        } 
        else
        {
            max_one = max(max_one, count);
            count = 0;
        }
    }

    // Handles corner case if all element/ last element is 1
    return max(max_one, count);
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

    cout<<"Maximam Consesutive 1's are : "<<MaximumConsecutiveOnes(arr);
}