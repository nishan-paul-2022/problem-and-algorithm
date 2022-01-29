#include<bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int T,num,tem,sum;
    scanf("%d",&T);
    for(int i=1; i<=T; i++)
    {
        scanf("%d",&num);
        sum=0;
        for(int j=0; j<num; j++)
        {
            scanf("%d",&tem);
            if(tem>0)
                sum+=tem;
        }
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
