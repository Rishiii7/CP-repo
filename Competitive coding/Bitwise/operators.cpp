#include <iostream>
using namespace std;

int main()
{
    int x = 3;
    int y = 5;
    cout<<"\n Left shift : "<<(x << y);

    cout<<"\n Right shift : "<<(x >> y);

    cout<<"\n Bitwise AND : "<<(x & y);

    cout<<"\n Bitwise OR : "<<(x | y);

    cout<<"\n Bitwise XOR : "<<(x ^ y);

    cout<<"\n Negation : "<<(~x);

}
