#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int l,r,i,j,k,rem,num2=0,num3=0,num6=0;
    cin>>l>>r;
    j=0;
    for(i=log2(l); j<=r; i++)
    {
        j=pow(2,i);
        if(j>=l && j<=r)
            num2++;
    }
    j=0;
    for(i=log2(l)/log2(3); j<=r; i++)
    {
        j=pow(3,i);
        if(j>=l && j<=r)
            num3++;
    }
    j=l/6;
    for(i=j*6; i<=r; i+=6)
    {
        k=i;
        if(i>=l && i<=r)
        {
            rem=1;
            while(k/6)
            {
                rem=k%6;
                k=k/6;
            }
            rem=k%6;
            if(rem==0 || rem==2 || rem==3)
                num6++;
        }
    }
    cout<<(num3+num2+num6);

    return 0;
}
