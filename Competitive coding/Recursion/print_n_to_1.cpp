#include <iostream>
#include <iomanip>

using namespace std;

void Print_N_to_1(int n)
{
    if (n==0)
    {
        return;
    }

    cout<<n<<" ";
    Print_N_to_1(n-1);
}

void Print_1_to_N(int n)
{
    if (n == 0)
    {
        return ;
    }

    Print_1_to_N(n-1);
    cout<<n<<" ";
}

int main()
{
    int n;
    cout<<"Enter a Number : ";
    cin>>n;

    Print_N_to_1(n);
    cout<<endl;
    Print_1_to_N(n);
}