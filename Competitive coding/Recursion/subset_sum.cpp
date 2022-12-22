#include <iostream>
#include <vector>
#include<numeric>
#include <algorithm>
using namespace std;

/*
Problem :
Count all the subset of an array whose sum is equal to the given sum

Solution :
1. create subset using recursion with termination cond as index 0
2. instead of using another array to store the element which we are 
going to include (as we did in subset problem) we will substract the
element from the sum.
3. calculate sum of every subset 
4. return 1 if sums are equal otherwise 0

Time Complexity : O(2^n)

Note :- can also be done using Dynamic Programming (DP)
*/

int SubsetSum(vector <int> arr, int index, int sum)
{
    if (index == 0)
    {
        return (sum == 0 ) ? 1 : 0 ;
    }
    

    return ( SubsetSum( arr, index - 1, sum) + SubsetSum( arr, index -1 , sum - arr[index - 1]) );
}

int main()
{
    int n;
    cout<<"Enter length of array : ";
    cin>>n;
    vector <int> arr(n);
    cout<<"Enter elements of array : ";
    for (int i = 0; i < n; i ++)
    {
        cin>>arr[i];
    }
    int sum;
    cout<<"Enter the given sum : ";
    cin>>sum;

    cout<<"No of Subset : "<<SubsetSum( arr, arr.size(), sum );

}