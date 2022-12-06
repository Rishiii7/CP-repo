#include <iostream>
using namespace std;

int main()
{
    int x,k;
    cout<<"\n Enter two numbers : ";
    cin>>x>>k;

    if ( (x>> (k-1)) & 1 )
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}