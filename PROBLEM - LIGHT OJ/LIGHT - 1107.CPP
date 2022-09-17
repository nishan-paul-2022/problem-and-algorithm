///IRON_BAT
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,i,j,n,x1,y1,x2,y2,row,column;
    cin>>T;
    for(i=1; i<=T; i++)
    {
        cin>>x1>>y1>>x2>>y2;
        cin>>n;
        printf("Case %d:\n",i);
        for(j=0; j<n; j++)
        {
            cin>>row>>column;
            if( (x1<row && row<x2) && (y1<column && column<y2) )
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
