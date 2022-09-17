#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    map<char,char> m;
    m['>']='<';
    m['<']='>';
    string f[3], ctch="";
    cin>>f[0]>>f[1]>>f[2];
    for(ll i=0; i<3; i++){
        if(f[i][0]=='B' && f[i][2]=='A'){
            swap(f[i][0],f[i][2]);
            f[i][1]=m[ f[i][1] ];
        }
        else if(f[i][0]=='C' && f[i][2]=='B'){
            swap(f[i][0],f[i][2]);
            f[i][1]=m[ f[i][1] ];
        }
        else if(f[i][0]=='C' && f[i][2]=='A'){
            swap(f[i][0],f[i][2]);
            f[i][1]=m[ f[i][1] ];
        }
    }
    map<ll,string> m1;
    for(ll i=0; i<3; i++)
        if(f[i][0]=='A' && f[i][2]=='B')
            m1[0]=f[i];
        else if(f[i][0]=='B' && f[i][2]=='C')
            m1[1]=f[i];
        else if(f[i][0]=='A' && f[i][2]=='C')
            m1[2]=f[i];
    for(auto i:m1)
        ctch+=i.second;
//    cout<<ctch<<lne;
    string str[6]={"A>BB>CA>C","A>BB<CA>C","A>BB<CA<C","A<BB>CA>C","A<BB>CA<C","A<BB<CA<C"};
    string patt[6]={"CBA","BCA","BAC","CAB","ACB","ABC"};
    string idx="Impossible";
    for(ll i=0; i<6; i++)
        if(ctch==str[i])
            idx=patt[i];
    cout<<idx;
    return 0;
}
