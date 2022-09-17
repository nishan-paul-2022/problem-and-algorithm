#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, N[1000],j=0;
    cin>>T;
    for(int i=0; i<1000; i++)
    {
        N[i]=j;
        j++;
        if(j==T)
            j=0;
    }
    for(int i=0; i<1000; i++)
    {
        printf("N[%d] = %d\n",i,N[i]);
    }
    return 0;
}
