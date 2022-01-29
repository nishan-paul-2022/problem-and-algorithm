#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
#define fst first
#define sec second
#define sq(a) ((a)*(a))
using namespace std;
pair<double,double> a,b,c,d;
double dis(double k){
    pair<double,double> p,q;
    p.fst=a.fst+k*(b.fst-a.fst);
    p.sec=a.sec+k*(b.sec-a.sec);
    q.fst=c.fst+k*(d.fst-c.fst);
    q.sec=c.sec+k*(d.sec-c.sec);
    return sqrt( sq(p.fst-q.fst)+sq(p.sec-q.sec) );
}
int main()
{
    ll T;
    cin>>T;
    for(ll i=1; i<=T; i++){
        cin>>a.fst>>a.sec>>b.fst>>b.sec>>c.fst>>c.sec>>d.fst>>d.sec;
        double lw=0, hgh=1;
        double lft, rht;
        while(hgh-lw>0.00000001){
            lft=lw+(hgh-lw)/3.0;
            rht=lw+2*(hgh-lw)/3.0;
            if(dis(lft)<dis(rht)) hgh=rht;
            else lw=lft;
        }
        cout<<"Case "<<i<<": "<<fixed<<setprecision(7)<<dis(hgh)<<lne;
    }
    return 0;
}

