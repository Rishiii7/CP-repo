#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

/*
Problem :
Maximum Difference problem is to find the maximum of arr[j] - arr[i] where j>i.

Time Complexity : thetha(n)
Aux Space Complexity : thetha(1)

Solution can also be written :

int i = 0;
int j = 1;
max_diff = arr[j] - arr[i]
min_val = arr[i]
for(int j= 1;j<len;j++)
{
    int diff = arr[j] - min_val;
    max_diff = max(max_diff , diff) 
    min_val = min(arr[j], min_val)
}

*/
int MaximumDiffWithOrder(vector <int> arr )
{
    /*
    Params :
    arr : Integer Vector
    
    Return : Integer
    
    Variable :
    i,j : Index of array
    len : Length of array
    max_diff, diff : difference in j and i th index of array
    */
    int i = 0;
    int j = 1;
    int max_diff = arr[j] - arr[i];
    int len = arr.size();
    while( j < len)
    {
        int diff = arr[j] - arr[i];
        max_diff = max(max_diff , diff);

        if(arr[j] < arr[i])
        {
            i = j;
        }
        j ++ ;
    }

    return max_diff;

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

    cout<<"Maximum Diff is : "<<MaximumDiffWithOrder(arr);
}