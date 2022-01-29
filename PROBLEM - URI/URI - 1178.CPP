#include<bits/stdc++.h>
using namespace std;
int main()
{
    double d,N[100];
    cin>>d;
    for(int i=0; i<100; i++)
    {
        N[i]=d;
        d=d/2;
        printf("N[%d] = %.4lf\n",i,N[i]);
    }
    return 0;
}

