#include <iostream>
#include <vector>
using namespace std;

/*
Problem:
check if sum is present in the subarray of the given sum
NOTE :- all values in an array are non-negative

Time complexity :- O(n)
Aux Space complexity :- O(1)
*/

bool SubarrayWithGivenSum(vector <int> arr, int sum)
{
    /*
    Params:
    arr : Integer Vector
    sum : Integer -- value to be find in the subarray

    Returns:
    Boolean value

    Variable :
    n : Integer -- size of array
    s,e : Integer -- starting and ending index of window
    curr_sum : Integer -- stores the sum of given window
    */
    int n = arr.size();
    int curr_sum = arr[0];
    int s = 0;
    int e = 0;

    while (e < n)
    {
        if (curr_sum == sum)
        {
            return true;
        }

        // if current sum is less increment the window size
        if(curr_sum < sum)
        {
            e ++;
            curr_sum += arr[e];
        }
        // if current sum is grater than decrement the window size
        else
        {
            curr_sum -= arr[s];
            s ++ ;
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

    cout<<"Enter the sum : ";
    cin>>sum;

    //calling function
    if (SubarrayWithGivenSum(arr, sum))
    {
        cout<<"Given sum is present";
    }
    else
    {
        cout<<"Givem sum is not present";
    }

}