#include<bits/stdc++.h>
#define ll long long
#define lne '\n'
#define spc ' '
#define sq(a) ((a)*(a))
using namespace std;
class cord
{
    public:
        double fst, sec, thr;
};
cord a,b,c;
double dis(double k){
    cord p,q;
    p.fst=a.fst+k*(b.fst-a.fst);
    p.sec=a.sec+k*(b.sec-a.sec);
    p.thr=a.thr+k*(b.thr-a.thr);
    return sqrt( sq(p.fst-c.fst)+sq(p.sec-c.sec)+sq(p.thr-c.thr) );
}
int main()
{
    ll T;
    cin>>T;
    for(ll i=1; i<=T; i++){
        cin>>a.fst>>a.sec>>a.thr>>b.fst>>b.sec>>b.thr>>c.fst>>c.sec>>c.thr;
        double lw=0, hgh=1;
        double lft, rht;
        while(hgh-lw>0.000000001){
            lft=lw+(hgh-lw)/3.0;
            rht=lw+2*(hgh-lw)/3.0;
            if(dis(lft)<dis(rht)) hgh=rht;
            else lw=lft;
        }
        double d=(hgh+lw)/2.0;
        printf("Case %lld: %.8lf\n",i,dis(d));
    }
    return 0;
}
