#include <iostream>
#include <vector>
using namespace std;

/*
Problem : 
Given an integer, we need to find floor of its square root

Time Complexity :- O(logn)
Aux Space Complexity :- O(1)
*/

int SqaureRoot(int ele)
{
    /*
    Params :
    ele : Integer -- find sqrt of ele
    
    Return : Integer
    
    Variables :
    low,high : Integer -- range that an sqaure root would be found
    mid : Integer -- mid ele of range
    ans : Integer -- storing possible sqrt
    */
    int low = 1, high = ele;
    int mid ; 
    int ans;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if( (mid * mid) == ele )
        {
            return mid;
        }
        else if ( (mid*mid) > ele)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int main()
{
    int ele;

    cout<<"Enter the element : ";
    cin>>ele;

    cout<<"Sqaure root of the element is : "<<SqaureRoot(ele);
}