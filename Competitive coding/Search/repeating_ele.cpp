#include <iostream>
#include <vector>

using namespace std;

/*
Problem : 
Find the reapeting element where,
Array Size n >= 2
Only one element is reapeating
all elements lies in 0 <= max(arr) <= n-2

Tortoise - Hair Algorithm also called as Floyd's algorithm

Time Complexity :- O(n)
Aux Space Complexity :- O(1)
*/
int RepeatingElement(vector <int> arr)
{
    /*
    Params :
    arr : Integer vector
    
    Variables :
    n : Integer -- size of vector
    slow, fast : Integer -- Indices of vector
    
    Return : Integer
    */
    int n = arr.size();
    int slow = arr[0] + 1, fast = arr[0] + 1;

    // phase 1 logic
    do
    {
        /* code */
        slow = arr[slow] + 1;
        fast = arr[arr[fast] + 1] + 1;

    } while (slow != fast);

    //phase 2 logic
    slow = arr[0] + 1;

    while (slow != fast)
    {
        /* code */
        slow = arr[slow] + 1;
        fast = arr[fast] + 1;

    }

    return slow - 1;  
    
}


int main()
{
    //initialize
    vector <int> arr;
    int n,ele;
    int x;
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

    // Print repeating element
    cout<<"Repeating Element is : "<<RepeatingElement(arr);
}