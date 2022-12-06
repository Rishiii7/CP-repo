#include <iostream>
using namespace std;

/*
Power Set :-  Bitwise Operator
Time complexity :- O(2^n * n)
Aux Space omplexity :- 
*/

void PowerSet(string s)
{
    int n = s.length();
    int p_size = 1 << n;
    cout<<" "<<endl;
    for(int i = 0 ; i < p_size ; i++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            if ( (i & (1 << j) ) != 0)
            {
                cout<<s[j];
            }
        }
        cout<<endl;
    }
}

int main()
{
    string s;
    cout<<"Enter a string : ";
    cin>>s;
    PowerSet(s);
    
}