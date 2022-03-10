///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
#define fst first
#define sec second
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
using namespace std;
int main()
{
    inout
    //fileopen
    ll n, x,y,sx,sy,ex,ey, chk=0;
    cin>>n;
    cin>>x>>y;
    cin>>sx>>sy;
    cin>>ex>>ey;
    if(1<=sx && sx<=x)
        if(1<=sy && sy<=y)
            if((1<=ex && ex<=x) && (1<=ey && ey<=y))
                chk=1;
        else if(y<=sy && sy<=n)
            if((1<=ex && ex<=x) && (y<=ey && ey<=n))
                chk=1;
    else if(x<=sx && sx<=n)
        if(1<=sy && sy<=y)
            if((x<=ex && ex<=n) && (1<=ey && ey<=y))
                chk=1;
        else if(y<=sy && sy<=n)
            if((x<=ex && ex<=n) && (y<=ey && ey<=n))
                chk=1;
    if(chk) cout<<"YES";
    else cout<<"NO";
    //fileclose
    return 0;
}

