///CUET_IRON_BAT
#include<bits/stdc++.h>
#define ll long long
#define vll vector<long long>
#define lne '\n'
#define spc ' '
#define fst first
#define sec second
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
using namespace std;
double equ(double x,double y,double w){
    double p=sqrt(x*x-w*w);
    double q=sqrt(y*y-w*w);
    double c=(p*q)/(p+q);
    return c;
}
int main()
{
    inout
//    fileopen
    double x,y,c;
    while(cin>>x>>y>>c){
        double a=0, b=min(x,y), w; ///fg
        while(1){
            w=(a+b)/2;
            double c1=equ(x,y,w);
            if(abs(c1-c)<=0.00001) break;
            else if(c1>c) a=w;
            else if(c1<c) b=w;
        }
        cout<<fixed<<setprecision(3)<<w<<lne;
    }
//    fileclose
    return 0;
}
