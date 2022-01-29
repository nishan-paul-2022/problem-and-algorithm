///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vli vector<long long>::iterator
#define vvl vector< vector<long long> >
#define vvli vector< vector<long long> >::iterator
#define vul vector<unsigned long long>
#define vuli vector<unsigned long long>::iterator
#define pll pair<long long,long long>
#define vpll vector< pair<long long,long long> >
#define vplli vector< pair<long long,long long> >::iterator
#define pls pair<long long,string>
#define vpls vector< pair<long long,string> >
#define vplsi vector< pair<long long,string> >::iterator
#define psl pair<string,long long>
#define vpsl vector< pair<string,long long> >
#define vpsli vector< pair<string,long long> >::iterator
#define vvpll vector< vector< pair<long long,long long> > >
#define vvplli vector< vector< pair<long long,long long> > >::iterator
#define mll map<long long,long long>
#define mlli map<long long,long long>::iterator
#define msl map<string,long long>
#define msli map<string,long long>::iterator
#define mls map<long long,string>
#define mlsi map<long long,string>::iterator
#define ud unsigned double
#define vd vector<double>
#define vdi vector<double>::iterator
#define vvd vector< vector<double> >
#define vvdi vector< vector<double> >::iterator
#define vud vector<unsigned double>
#define vudi vector<unsigned double>::iterator
#define pdd pair<double,double>
#define vpdd vector< pair<double,double> >
#define vpddi vector< pair<double,double> >::iterator
#define pds pair<double,string>
#define vpds vector< pair<double,string> >
#define vpdsi vector< pair<double,string> >::iterator
#define psd pair<string,double>
#define vpsd vector< pair<string,double> >
#define vpsdi vector< pair<string,double> >::iterator
#define vvpdd vector< vector< pair<double,double> > >
#define vvpddi vector< vector< pair<double,double> > >::iterator
#define mdd map<double,double>
#define mddi map<double,double>::iterator
#define msd map<string,double>
#define msdi map<string,double>::iterator
#define mds map<double,string>
#define mdsi map<double,string>::iterator
#define vs vector<string>
#define vsi vector<string>::iterator
#define vb vector<bool>
#define vbi vector<bool>::iterator
#define vtrpl vector<trpl>
#define vtrpli vector<trpl>::iterator
#define vvtrpl vector< vector<trpl> >
#define vvtrpli vector< vector<trpl> >::iterator
#define pushb push_back
#define pushf pop_front
#define popb pop_back
#define popf push_front
#define mpair make_pair
#define tostring to_string
#define sqr(n) (n*n)
#define cube(n) (n*n*n)
#define mem(a,b) memset(a,b,sizeof(a))
#define lne '\n'
#define spc ' '
#define ff first
#define ss second
#define mod 1000000007
#define PI acos(-1)
#define infp 9223372036854775807
#define infn -9223372036854775808
#define inf 18446744073709551615
#define lsw(n) left<<setw(n)
#define rsw(n) right<<setw(n)
#define usp(n) cout.unsetf(ios::fixed); cout<<setprecision(n);
#define fsp(n) cout.setf(ios::fixed); cout<<setprecision(n);
#define normal cout.setf(ios::fixed); cout<<setprecision(6);
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("accurate.txt"); system("input.txt"); FILE *my1=freopen("input.txt","r",stdin); FILE *my2=freopen("output.txt","w",stdout);
#define fileclose fclose(my1); fclose(my2); system("output.txt"); freopen("CON","w",stdout); string s1="accurate.txt",s2="output.txt"; char *name1=&s1[0], *name2=&s2[0]; FILE *f1=fopen(name1,"r"), *f2=fopen(name2,"r");char c1(spc), c2(spc);if(!f1){ cout<<s1<<" doesn't EXIST"<<lne; exit(0);} if(!f2){ cout<<s2<<" doesn't EXIST"<<lne; exit(0);}ll ex=0, ey=0;while(c1!=EOF && c2!=EOF){c1=getc(f1); c2=getc(f2);if(c1==lne){ ex++; ey=0;}if(c1!=c2){cout<<"ERROR at "<<"("<<1+ex<<","<<ey<<")"<<lne;cout<<c1<<" INSTEAD of "<<c2<<lne;exit(0);}ey++;}fclose(f1); fclose(f2);cout<<"NO ERROR"<<lne;
using namespace std;
class srt
{
    public:
        void insertion(vector<ll> &v){
            ll n=v.size();
            for(ll i=1; i<n; i++){
                ll j=i-1, value=v[i];
                while(j>=0 && v[j]>value){
                    swap(v[j],v[j+1]);
                    j--;
                }
            }
        }
        void selection(vector<ll> &v){
            ll n=v.size();
            for(ll i=0; i<n-1; i++){
                for(ll j=i+1; j<n; j++){
                    if(v[i]>v[j])
                        swap(v[i],v[j]);
                }
            }
        }
        void bubble(vector<ll> &v){
            ll n=v.size();
            for(ll i=0; i<n-1; i++)
                for(ll j=0; j<n-1; j++)
                    if(v[j]>v[j+1])
                        swap(v[j],v[j+1]);
        }
        ll quick_part(vector<ll> &v,ll s,ll e){
            ll pvt=v[e], i=s-1;
            for(ll j=s; j<e; j++){
                if(v[j]<pvt){
                    i++;
                    swap(v[i],v[j]);
                }
            }
            swap(v[i+1],v[e]);
            return i+1;
        }
        void quick(vector<ll> &v,ll s,ll e){
            if(s>=e) return;
            ll p=quick_part(v,s,e);
            quick(v,s,p-1);
            quick(v,p+1,e);
        }
        void mrg_array(vector<ll> &v,ll s,ll m,ll e){
            vector<ll> left,right;
            for(ll i=s; i<=m; i++)
                left.push_back(v[i]);
            for(ll i=m+1; i<=e; i++)
                right.push_back(v[i]);
            ll i=0, j=0, k=s;
            while(i<=m-s && j<=e-m-1)
                if(left[i]>=right[j])
                    v[k++]=right[j++];
                else if(left[i]<right[j])
                    v[k++]=left[i++];
            while(i<=m-s)
                v[k++]=left[i++];
            while(j<=e-m-1)
                v[k++]=right[j++];
        }
        void mrg(vector<ll> &v,ll s,ll e){
            if(s<e){
                ll m=(s+e)/2;
                mrg(v,s,m);
                mrg(v,m+1,e);
                mrg_array(v,s,m,e);
            }
        }
        void counting(vector<ll> &v,ll mx){
            vector<ll> value, cnt(mx+1,0);
            ll n=v.size();
            for(ll i=0; i<n; i++)
                cnt[v[i]]++;
            for(ll i=0; i<=mx; i++){
                if(cnt[i]){
                    while(cnt[i]){
                        value.push_back(i);
                        cnt[i]--;
                    }
                }
            }
            v=value;
        }
};
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main()
{
    int n,k,val;
    cin>>n>>k;
//    vl a(n);
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
//    random_shuffle(a.begin(),a.end());
//    srt omg;
//    omg.mrg(a,0,n);
//    sort(a,a+n);
    qsort(a, n, sizeof(int), cmpfunc);
    if(k==0)
        val=a[0]-1;
    else{
        if(a[k-1]==a[k]) val=-1;
        else val=a[k-1];
    }
    if(val<1) cout<<-1;
    else cout<<val;
    return 0;
}
