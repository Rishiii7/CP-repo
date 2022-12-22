#include <iostream>
using namespace std;

/*
Problem :
We need to remove Dics from Tower A to Tower C 
in the same Fashion while using Tower B as auxilary tower

Rules :
1. Only one Dics can be removed one at a time
2. Samller dics should always be above the Larger Dics at any point of time in tower
3. Only Top dics of the Tower can be removed

Solution :
Intermediate step in this problem is to move n-1 dics from 
Tower A to B ( i.e our function call is TOH(n-1, source (A), aux(C), destination(B) )), 
then move n-th dics from Tower A to C (i.e line 38),
and lastly move n-1 dics from Tower B to C
(i.e TOH(n-1, source(B), aux(A), destination(C) )) 

*/

void TOH(int n , char A, char B, char C)
{
    /*
    Params :
    n : No of Dics in Tower A - initially
    A, B, C : Towers of Hanoi

    Returns :
    None
    */
    if (n == 1)
    {
        cout<<"Move 1 from "<<A<<" to "<<C<<endl;
        return ;
    }

    TOH(n-1, A, C, B);
    cout<<"Move "<<n<<" from " << A << " to "<< C<<endl;
    TOH(n-1, B, A,C);
}


int main()
{
    int n;
    cout<<"Enter the Number of Dics: ";
    cin>>n;
    TOH(n, 'A', 'B', 'C');
}