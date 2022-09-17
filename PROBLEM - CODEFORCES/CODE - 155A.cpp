#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,ma,mi,hud,tem,sum=0 ;
    cin>>n ;
    for(int i=0; i<n; i++)
    {
        cin>>tem ;
        if(i==0)
        {
            ma=tem ;
            mi=tem ;
        }
        else if(i==1)
        {
            if(tem!=hud)
            {
                sum++ ;
            }
        }
        else
        {
            ma=max(ma,hud) ;
            mi=min(mi,hud) ;
            if(tem!=hud)
            {
                if(tem>ma)
                {
                    sum++ ;
                    ma=tem ;
                }
                else if(tem<mi)
                {
                    sum++ ;
                    mi=tem ;
                }
            }
        }
        hud=tem ;
    }
    cout<<sum ;
    return 0 ;
}

