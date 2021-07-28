#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
int togglebit(int n)
{
    if (n == 0)
        return 1;

    int i = n;

    // Below steps set bits after
    // MSB (including MSB)

    // Suppose n is 273 (binary
    // is 100010001). It does following
    // 100010001 | 010001000 = 110011001
    n |= n >> 1;

    // This makes sure 4 bits
    // (From MSB and including MSB)
    // are set. It does following
    // 110011001 | 001100110 = 111111111
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    return i ^ n;
}

// Returns XNOR of num1 and num2
int XNOR(int num1, int num2)
{
    // if num2 is greater then
    // we swap this number in num1
    if (num1 < num2)
        swap(num1, num2);
    num1 = togglebit(num1);

    return num1 ^ num2;
}
int main()
{
    fast
    ll t,a,b,n,i,x[10000],e[10000];
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        x[1]=e[1]=a;
        x[2]=e[2]=b;
        for(i=3;i<n+1;++i)
        {
           x[i]=x[i-1]^x[i-2];
           e[i]=XNOR(e[i-1],e[i-2]);
        }
        cout<<max(e[n],x[n])<<"\n";

    }
}
