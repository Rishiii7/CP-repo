#include<iostream>
#include<algorithm>
#include <initializer_list>
using namespace std;
/*
You are given a length of the rope and 3 parameter 
where the rope can only be cut using the parameters given
return no.of maximum cuts you can make
if cuts are not possible return -1

Here,
n : length of the rope
a, b, c : possible cuts one can make

Time Complexity :- 0(3^n)

this problem can be optimized using dynamic programming
*/

int MaxNo_OfCuts(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n < 0)
    {
        return -1;
    }

    int res = max( MaxNo_OfCuts(n-a,a,b,c) , 
                max(MaxNo_OfCuts(n-b,a,b,c) , MaxNo_OfCuts(n-c,a,b,c)) );

    if (res == -1)
    {
        return -1;
    }

    return res + 1;
    
}

int main()
{
    int n,a,b,c;
    cout<<"Enter the length of the rope : ";
    cin>>n;
    cout<<"Enter 3 possible cuts you can make : ";
    cin>>a>>b>>c;
    cout<<MaxNo_OfCuts(n,a,b,c);
}