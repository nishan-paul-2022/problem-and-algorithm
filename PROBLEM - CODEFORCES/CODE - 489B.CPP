///IRON_BAT
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
//    system("input.txt");
//    freopen("input.txt","r",stdin);
//    FILE *f=freopen("output.txt","w",stdout);

    vector<ll> v, v1;
    ll n,m,i,tem,j,result=0 ;
    scanf("%lld",&n);
    for(i=0; i<n; i++)
    {
        scanf("%lld",&tem);
        v.push_back(tem);
    }
    scanf("%lld",&m);
    for(i=0; i<m; i++)
    {
        scanf("%lld",&tem);
        v1.push_back(tem);
    }
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(v[i]!=0 && v1[j]!=0)
                if( abs(v[i]-v1[j])==0 || abs(v[i]-v1[j])==1 )
                {
                    result++;
                    v[i]=v1[j]=0;
                }
        }
    }
    printf("%lld",result);

//    fclose(f);
//    system("output.txt");
    return 0;
}



