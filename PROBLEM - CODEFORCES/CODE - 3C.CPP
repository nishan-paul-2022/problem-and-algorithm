///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
using namespace std;
int main()
{
    ll cros=0, zro=0, x=0, o=0, idx=0;
    string s[3];
    getline(cin,s[0],lne);
    getline(cin,s[1],lne);
    getline(cin,s[2],lne);
    for(ll i=0; i<3; i++){
        for(ll j=0; j<3; j++){
            if(s[i][j]=='0') zro++;
            else if(s[i][j]=='X') cros++;
        }
    }
    if( s[1][1]!='.' && ((s[0][0]==s[1][1] && s[1][1]==s[2][2]) || (s[0][2]==s[1][1] && s[1][1]==s[2][0])) ){
        if(s[1][1]=='X') x=1;
        else if(s[1][1]=='0') o=1;
    }
    for(ll i=0; i<3; i++){
        if( (s[i][0]==s[i][1] && s[i][1]==s[i][2] && s[i][1]!='.') || (s[0][i]==s[1][i] && s[1][i]==s[2][i] && s[1][i]!='.') ){
            if(s[idx][idx]=='X') x=1;
            else if(s[idx][idx]=='0') o=1;
        }
        idx++;
    }
    ll val=cros-zro;
    if( val>1 || val<0 || (x==1 && val!=1) || (o==1 && val!=0) )
        cout<<"illegal";
    else{
        if(x==1) cout<<"the first player won";
        else if(o==1) cout<<"the second player won";
        else if(x==0 && o==0){
            if(cros+zro==9) cout<<"draw";
            else if(val==0) cout<<"first";
            else if(val==1) cout<<"second";
        }
    }
    return 0;
}
