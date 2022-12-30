#include <iostream>
#include <vector>
using namespace std;
/* 
Problem :
find maximum circular sum subarray of a given array

Solution :
1. find maximum sum of subarray without circular conditions 
2. invert all the element of array (i.e multiply by -1)
3. find maximum sum of subarray without circular conditions with new array
    and add to the sum of array
    (idea behind is that if we substract min sub array from total sum of the array
    we get max sum of subarray)
4. return the maximum out of both
*/

int MaximumSumSubarray(vector <int> arr)
{
    /*
    Params :
    arr : Integer Vector

    Returns :
    Integer

    Variables :
    max_sum, max_prev : Integer -- storing max sum of subarray and 
                                   max sum of previous 0-ith array
    n : Integer -- size of array
    */
    int max_prev = arr[0];
    int max_sum = arr[0];
    int n = arr.size();

    for(int i = 1 ; i < n ; i++)
    {
        max_prev = max(max_prev + arr[i], arr[i]);
        max_sum = max(max_prev, max_sum);
    }

    return max_sum;
}

int MaxCircularSumSubarray(vector <int> arr)
{
    /*
    Params :
    arr : Integer Vector

    Returns :
    Integer

    Variables :
    max_normal, max_circular : Integer -- storing max sum of subarray and 
                                   max sum of previous 0-ith array
    n : Integer -- size of array
    sum : Integer -- sum of original array
    */
    int max_normal = MaximumSumSubarray(arr);
    int n = arr.size();
    int sum = 0;

    // corner case 
    if (max_normal < 0)
    {
        return max_normal;
    }

    for(int i = 0; i < n ; i++)
    {
        sum += arr[i];
        arr[i] = -1 * arr[i];
    }

    int max_cirular = sum + MaximumSumSubarray(arr);

    return max(max_normal, max_cirular);
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

    cout<<"Maximum sum of Circular subarray is : "<<MaxCircularSumSubarray(arr);
}