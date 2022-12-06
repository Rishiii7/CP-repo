#include <iostream>
#include<vector>
using namespace std;

/*
Count of set Bits :- Lookup Table
*/
vector <int> LookUpTable(256);

int CountSetBit_LUT(int n)
{
    int count = LookUpTable[n & 255] + LookUpTable[ (n>>8) & 255 ] + LookUpTable[(n>>16) & 255] + LookUpTable[(n>>24) & 255];
    return count;
}


/*
Count of set Bits :- Brial Keriningam's Algorithm
Time Complexity :- O(set bits)
Aux Space complexity :- O(1)
*/

int CountSetBit_EfficientMethod(int n)
{
    int count = 0;
    while (n>0)
    {
        n = n & (n-1);
        count ++;
    }

    return count;
}

/*
Count of set Bits :- Naive Solution
Time Complexity :- O(log(n))
Aux Space complexity :- O(1)
*/
int count_set_bit(int n)
{
    int count = 0;
    if (n & 1)
    {
        count ++;
    }
    while (n > 0)
    {
        if ( (n>>1) & 1)
        {
            count ++;
        }
        n = n >> 1 ;
    }

    return count;
}

// Driver function
int main()
{
    int x;
    cout<<"\n Enter a number : ";
    cin>>x;

    //cout<<"\n Number of 1's are using Naive method : "<<count_set_bit(x);

    //cout<<"\n Number of 1's are using Efficient method : "<<CountSetBit_EfficientMethod(x);

    // Populate the look up table
    LookUpTable[0] = 0;
    for (int i = 1;i<= 255;i++)
    {
        LookUpTable[i] = LookUpTable[i & (i-1)] + 1;

    }

    cout<<"\n Number of 1's are using Look up table method : "<<CountSetBit_LUT(x);



    
}