#include<bits/stdc++.h>
#define ll long long int
#define line '\n'
using namespace std;
int main()
{
    ll n, mku=0,msh=0,mka=0;
    cin>>n;
    string ku,sh,ka;
    cin>>ku>>sh>>ka;
    vector<ll> v1(52,0), v2(52,0), v3(52,0);
    for(ll i=0; i<ku.size(); i++)
    {
        char c=ku[i];
        if(97<=c && c<=122){
            v1[c-97]++;
            mku=max(mku,v1[c-97]);
        }
        else{
            v1[c-39]++;
            mku=max(mku,v1[c-39]);
        }
    }
    for(ll i=0; i<sh.size(); i++)
    {
        char c=sh[i];
        if(97<=c && c<=122){
            v2[c-97]++;
            msh=max(msh,v2[c-97]);
        }
        else{
            v2[c-39]++;
            msh=max(msh,v2[c-39]);
        }
    }
    for(ll i=0; i<ka.size(); i++)
    {
        char c=ka[i];
        if(97<=c && c<=122){
            v3[c-97]++;
            mka=max(mka,v3[c-97]);
        }
        else{
            v3[c-39]++;
            mka=max(mka,v3[c-39]);
        }
    }
    if(mku==msh && msh==mka)
        cout<<"Draw";

    else if(mku>msh && msh>=mka)
        cout<<"Kuro";

    else if(msh>mka && mka>=mku)
        cout<<"Shiro";

    else if(mka>mku && mku>=msh)
        cout<<"Katie";

    else if(mku>msh && msh<mka){
        if(mku>mka)
            cout<<"Kuro";
        else if(mku==mka)
            cout<<"Draw";
        else
            cout<<"Katie";
    }

    else if(msh>mka && mka<mku){
        if(msh>mku)
            cout<<"Shiro";
        else if(msh==mku)
            cout<<"Draw";
        else
            cout<<"Kuro";
    }

    else if(mka>mku && mku<msh){
        if(mka>msh)
            cout<<"Katie";
        else if(mka==msh)
            cout<<"Draw";
        else
            cout<<"Shiro";
    }
    return 0;
}
