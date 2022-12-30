#include <iostream>
#include <vector>
using namespace std;
/*
Problem :
find the majority element form given array. Majority element is an 
element that appears more than n/2 times in an array of size n.

Solution :
Moore's Voting algorithm ==>
1.  we will set the count variable to 1 
2.  if element found is same then increment the count otherwise decrement
3.  if count equates to zero reset the count and assign index to the i-th index
4.  write another loop for checking if element found on the index
        is actually having count as >= n/2

Time Complexity :- O(n)
Aux Space Complexity :- O(1)
*/

int MajorityElelment(vector <int> arr)
{
    /*
    Params:
    arr : Integer Vector

    Returns:
    Integer

    Variable :
    count,count_ele : Integer, Integer
    n : Integer -- size of array
    */
    int count = 1;
    int ind = 0;
    int n = arr.size();

    // finding the majority element
    for(int i = 1 ; i < n ; i++)
    {
        if (arr[ind] == arr[i])
        {
            count ++ ;
        }
        else
        {
            count --;
        }

        if(count == 0)
        {
            ind = i;
            count = 1;
        }
    }

    // checking if element found is mojoriy or not
    int count_ele = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[ind] == arr[i])
        {
            count_ele ++;
        }
    }

    if (count_ele <= n/2)
    {
        return -1;
    }

    return arr[ind];
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

    cout<<"Majority element is : "<<MajorityElelment(arr);
}