#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,T;
    long long int Fib[61];
    Fib[0]=0, Fib[1]=1;
    for(i=2; i<=60; i++)
    {
        Fib[i]=Fib[i-1]+Fib[i-2];
    }
    cin>>T;
    while(T--)
    {
        long long int tem;
        cin>>tem;
        printf("Fib(%lld) = %lld\n",tem,Fib[tem]);
    }
    return 0;
}
