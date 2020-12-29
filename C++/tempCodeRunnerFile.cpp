#include<iostream>
using namespace std;
int reverse(int x)
{
    int ret=0;
    bool zero= false;
    while(!zero)
    {
        ret= ret*10+(x%10);
        x /= 10;      
        if(x == 0)
        {
            zero = true;
        }
    }
    return ret;
}
int main()
{
    int s = 1000000003;
    cout<<reverse(s);
}