///CUET_IRON_BAT
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h,m,n,s,t,i,test=0,up=0,value=0;
    cin>>n>>s;
    t=s*2+2;
    for(i=0; i<n; i++)
    {
        cin>>h>>m;
        if(test==0)
        {
            h=h*60+m;
            if(i==0) up=h;
            if(i==0 && h>=s+1)
            {
                value=0;
                test=1;
            }
            else if(h-up>=t)
            {
                value=up+s+1;
                test=1;
            }
            else
            {
                up=h;
                value=h+s+1;
            }
        }
    }
    cout<<(value/60)<<" "<<(value%60);
    return 0;
}

