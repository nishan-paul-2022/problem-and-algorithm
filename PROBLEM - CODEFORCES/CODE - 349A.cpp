#include<iostream>
using namespace std ;
int main()
{
    long long int n,i,tem,n25=0,n50=0 ;
    cin>>n ;
    for(i=0; i<n; i++)
    {
        cin>>tem ;
        if(i==0)
        {
            if(tem!=25)
            {
                cout<<"NO" ;
                return 0 ;
            }
            else
                n25++ ;
        }
        else
        {
            if(tem==25)
                n25++ ;
            else if(tem==50)
            {
                if(n25<1)
                {
                    cout<<"NO" ;
                    return 0 ;
                }
                else
                {
                    n25-- ;
                    n50++ ;
                }
            }
            else if(tem==100)
            {
                if(n25>=1 && n50>=1)
                {
                    n25-- ;
                    n50-- ;
                }
                else if(n25>=3)
                    n25=n25-3 ;
                else
                {
                    cout<<"NO" ;
                    return 0 ;
                }
            }
        }
    }
    if(i==n)
        cout<<"YES" ;
}

