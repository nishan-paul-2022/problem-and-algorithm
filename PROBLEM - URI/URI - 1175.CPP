#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N[20];
    for(int i=0; i<20; i++)
    {
        cin>>N[i];
    }
    for(int i=0; i<10; i++)
    {
       int tem;
       tem=N[i];
       N[i]=N[19-i];
       N[19-i]=tem;
    }
    for(int i=0; i<20; i++)
    {
        printf("N[%d] = %d\n",i,N[i]);
    }
    return 0;
}
