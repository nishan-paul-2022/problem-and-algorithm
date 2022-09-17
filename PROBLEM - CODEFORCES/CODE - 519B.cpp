///IRON_BAT
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
//    system("input.txt");
//    freopen("input.txt","r",stdin);
//    FILE *f=freopen("output.txt","w",stdout);

    ll error,a=0,b=0,c=0,i,tem;
    scanf("%lld",&error);
    for(i=0; i<error; i++)
    {
        scanf("%lld",&tem);
        a+=tem;
    }
    for(i=0; i<error-1; i++)
    {
        scanf("%lld",&tem);
        b+=tem;
    }
    for(i=0; i<error-2; i++)
    {
        scanf("%lld",&tem);
        c+=tem;
    }
    printf("%lld\n%lld",a-b,b-c);

//    fclose(f);
//    system("output.txt");
    return 0;
}

