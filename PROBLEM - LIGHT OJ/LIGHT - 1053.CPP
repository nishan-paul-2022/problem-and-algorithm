#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,i,value,arm,a[3];
    cin>>T;
    for(i=1; i<=T; i++)
    {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        value=pow(a[0],2)+pow(a[1],2);
        arm=pow(a[2],2);
        if(value==arm)
            printf("Case %d: %s\n",i,"yes");
        else
            printf("Case %d: %s\n",i,"no");
    }
    return 0;
}
