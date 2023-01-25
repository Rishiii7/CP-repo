#include <iostream>
#include <vector>
using namespace std;

/*
Probblem : 
Given a number of pages in N different books and M students. 
The books are arranged in ascending order of the number of pages. 
Every student is assigned to read some consecutive books. 
The task is to assign books in such a way that the maximum number
of pages assigned to a student is minimum. 

Time Complexity :- O(log(n))
Aux Space Complexity :- O(1)
*/


int CalculateSum(vector <int> arr, int i , int j)
{
    /*
    Params :
    arr : Integer Vector
    i, j : Integer -- Indecies range to calulat sum
    
    Variable :
    sum : Integer -- store the summation value
    
    Return : Integer
    */
    int sum = 0;
    for(int k = i ; k <= j; k++)
    {
        sum += arr[k];
    }

    return sum;
}

int MinimumPagesAllocated_Naive(vector <int> arr, int n, int k)
{
    /*
    Params :
    arr : Integer Vector
    n : Integer -- size of vector
    k : Integer -- no of students

    variable : 
    res : Integer -- final answer

    Return : Integer
    */
    if(k == 1)
    {
        return CalculateSum(arr, 0 , n - 1);
    }

    if (n == 1)
    {
        return arr[0];
    }

    int res = INT_MAX;

    for(int i = 0 ; i < n ; i ++)
    {
        res = min(res , max(MinimumPagesAllocated_Naive(arr, i , k-1) , CalculateSum(arr, i , n - 1)));
    }
    return res;
    
}


bool isFeasible(vector <int> arr , int max_sum , int k)
{
    /*
    Params :
    arr : Integer Vector
    max_sum : Integer -- maximum sum allowed
    k : Integer -- no of student
    
    variable : 
    n : Integer -- size of array
    sum : Integer
    freq : Integer -- to store no of student
    
    Return : Boolean
    */
    int n = arr.size();
    int sum = 0;
    int freq = 1;
    for(int i =0 ; i < n ; i ++)
    {
        if (sum + arr[i] > max_sum)
        {
            freq ++;
            sum = arr[i];
        }
        else
        {
            sum += arr[i];
        }
    }

    return (freq <= k);
}

int MinimumPagesAllocated_Efficient(vector <int> arr , int k)
{
    /*
    Params:
    arr : Integer Vector
    k : Integer -- no of students
    
    Variable :
    sum , max_ele : Integer -- to store total sum and maximum element
    n : Integer -- size of vector
    low,mid,high : Integer -- range of value where solution lies
    res : Integer -- final answer

    Return : Integer
    */
    int sum = 0, max_ele = 0;
    int n = arr.size();
    int low , high, mid;
    int res = 0;

    for(int i = 0 ; i< n ;i++)
    {
        sum += arr[i];
        max_ele = max(max_ele , arr[i]);
    }

    low = max_ele , high = sum;
    
    while (low <= high)
    {
        mid = (low + high) / 2;

        if(isFeasible(arr,mid,k))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return res;
    
}


int main()
{
    //initialize
    vector <int> arr;
    int n,ele;
    int x;
    int k;

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

    // enter no of student
    cout<<"Enter no of student : ";
    cin>>k;

    // print mini no of pages allocated using naive method
    //cout<<"Minimpages needed to be read is : "<<MinimumPagesAllocated_Naive(arr,arr.size(), k);

    // print mini no of pages allocated using binary search method
    cout<<"Minimpages needed to be read is : "<<MinimumPagesAllocated_Efficient(arr,k);
}