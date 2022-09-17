#include<bits/stdc++.h>
#define pi 2*acos(0.0)
using namespace std;
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int T,i;
    double rad,v_cir,v_cube,value;
    scanf("%d",&T);
    for(i=1; i<=T; i++)
    {
        cin>>rad;
        v_cube=pow(rad*2,2);
        v_cir=pi*rad*rad;
        value=v_cube-v_cir;
        printf("Case %d: %.2lf\n",i,value);
    }
    return 0;
}
