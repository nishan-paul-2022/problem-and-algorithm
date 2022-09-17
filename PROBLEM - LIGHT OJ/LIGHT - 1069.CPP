#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,i,me,lift,time;
    cin>>T;
    for(i=1; i<=T; i++)
    {
        cin>>me>>lift;
        if(me>lift)
            lift=me+(me-lift);
        time=19+(lift*4);
        printf("Case %d: %d\n",i,time);
    }
    return 0;
}
