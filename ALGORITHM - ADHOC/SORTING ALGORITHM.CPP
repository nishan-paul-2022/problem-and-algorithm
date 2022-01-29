///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define ud unsigned double
#define gcd __gcd
#define countbit __builtin_popcount
#define sqr(n) (n*n)
#define cube(n) (n*n*n)
#define lne '\n'
#define spc ' '
#define ff first
#define ss second
#define mod 29996224275833
#define PI acos(-1)
#define inf  ULLONG_MAX
#define infp LLONG_MAX
#define infn LLONG_MIN
#define lsw(n) left<<setw(n)
#define rsw(n) right<<setw(n)
#define usp(n) cout.unsetf(ios::fixed); cout<<setprecision(n);
#define fsp(n) cout.setf(ios::fixed); cout<<setprecision(n);
#define normal cout.setf(ios::fixed); cout<<setprecision(6);
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("fileb.txt"); FILE *my1=freopen("fileb.txt","r",stdin); FILE *my2=freopen("filec.txt","w",stdout);
#define fileclose fclose(my1); fclose(my2); system("filec.txt");
//#define fileopen system("filea.txt"); system("fileb.txt"); FILE *my1=freopen("fileb.txt","r",stdin); FILE *my2=freopen("filec.txt","w",stdout);
//#define fileclose fclose(my1); fclose(my2); system("filec.txt"); freopen("CON","w",stdout); string s1="filea.txt",s2="filec.txt"; char *name1=&s1[0], *name2=&s2[0]; FILE *f1=fopen(name1,"r"), *f2=fopen(name2,"r");char c1(spc), c2(spc);if(!f1){ cout<<s1<<" doesn't EXIST"<<lne; exit(0);} if(!f2){ cout<<s2<<" doesn't EXIST"<<lne; exit(0);}ll ex=0, ey=0;while(c1!=EOF && c2!=EOF){c1=getc(f1); c2=getc(f2);if(c1==lne){ ex++; ey=0;}if(c1!=c2){cout<<"ERROR at "<<"("<<1+ex<<","<<ey<<")"<<lne;cout<<c1<<" INSTEAD of "<<c2<<lne;exit(0);}ey++;}fclose(f1); fclose(f2);cout<<"NO ERROR"<<lne;
#define fileopenX fileopen ll test; cin >> test; for(ll cs = 1; cs <= test; cs++) {
#define filecloseX } fileclose
using namespace std;

/// BUBBLE n^2
/// SELECTION n^2
/// INSERTION n^2 [best when number of elements are less and are in nearly sorted form]
/// QUICK n^2 [most efficient algorithm in average case, when time complexity is n*log2(n)]
/// MERGE ( n + n*log2(n) ) [most efficient algorithm in the worst case]
/// COUNTING (N + n) [best when N<=n]
/// RADIX SORT (d*n)
/// BUCKET SORT (n+k)
/// sort(): 'INSTROSORT ALGORITHM'
///         quicksort(number of steps <= 2*log2(n)) + heapsort + insertion sort(when the size of array decreases)
///         time complexity nlog2(n) && memory complexity >= n
///         alter relative order of the elements
/// stable_sort(): 'TIMSORT ALGORITHM'
///                merge sort + insertion sort(when the size of array decreases)
///                time complexity - nlog2(n) when memory complexity can be greater than n
///                time complexity - n*( log2(n) )^2 when memory complexity must be n
///                does not alter relative order of the elements
/// partial_sort(): 'HEAPSORT'
///                 time complexity - n*log2(n)
///                 specifically it creates a max heap of all elements and then adjusts it in the range
/// [worst case will be generated when the array is in reverse order]
/// [bubble, selection, insertion, quick, merge - comparison based sort]
/// [counting, radix, bucket - integer sort]

ll getMax(vector<ll> v){
    ll n=v.size(), mx=v[0];
    for(ll i=1; i<n; i++){
        if(v[i] > mx)
            mx = v[i];
    }
    return mx;
}

class srt
{
    public:

        void bubble(vector<ll> &v){
            ll n=v.size();
            for(ll i=0; i<n-1; i++)
                for(ll j=0; j<n-1; j++)
                    if(v[j]>v[j+1])
                        swap(v[j],v[j+1]);
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

        ll quick_pivot(vector<ll> &v,ll s,ll e){
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
            ll p=quick_pivot(v,s,e);
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

        void radix_count(vector<ll> &v,ll n,ll exp){//to do counting sort of v[] according to the digit
            ll freq[10], store[n];
            fill(freq, freq+10, 0);
            for(ll i=0; i<n; i++){//storing the frequency of every digit in freq[]
                ll digit = (v[i]/exp) % 10;
                freq[digit]++;
            }
            for(ll i=1; i<10; i++){//changing freq[i] so that freq[i] now contains actual position of this digit in store[]
                freq[i] += freq[i-1];
            }
            for(ll i=n-1; i>=0; i--){//building the store[]
                ll digit = (v[i]/exp) % 10;
                ll f = freq[digit];
                store[f-1] = v[i];
                freq[digit]--;
            }
            for(ll i=0; i<n; i++){//transfering the store[] to v[], so that v[] now contains sorted values according to current digit
                v[i] = store[i];
            }
        }
        void radix(vector<ll> &v){
            ll n=v.size(), m=getMax(v);//finding the maximum value of v[]
            for (ll exp=1; m/exp > 0; exp*=10){//counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is current digit number
                radix_count(v, n, exp);
            }
        }

        void bucket(vector<double> &v){
            ll n = v.size();
            map< ll, vector<double> > b;
            for(ll i=0; i<n; i++){
                ll bi = 10*v[i];
                b[bi].push_back(v[i]);
            }
            ll index = 0;
            for(map< ll, vector<double> >::iterator it=b.begin(); it!=b.end(); it++){
                sort(it->ss.begin(), it->ss.end());
                ll sz = it->ss.size();
                for(ll i=0; i<sz; i++){
                    v[index++] = it->ss[i];
                }
            }
        }
        void bucketMixed(vector<double> &v){
            ll n = v.size();
            vector<double> neg, pos;
            for(ll i=0; i<n; i++){
                if(v[i] < 0)
                    neg.push_back( -1*v[i] );
                else
                    pos.push_back(v[i]);
            }
            bucket(neg);
            bucket(pos);
            ll szn = neg.size();
            for(ll i=0; i<szn; i++){
                v[i] = -1*neg[szn-1-i];
            }
            for(ll i=szn; i<n; i++){
                v[i] = pos[i-szn];
            }
        }

};

int main()
{
//    inout
//    fileopen

    srt omg;
    vector<ll> u,v;
    u = v = {6,8,5,9,7,2,4,1};
    ll n = u.size();
    sort( u.begin(), u.end()-3 );
    partial_sort( v.begin()+1, v.end()-3, v.end()-3 );
    for(ll i=0; i<n; i++) {
        cout<<u[i]<<spc;
    }
    cout<<lne;
    for(ll i=0; i<n; i++) {
        cout<<v[i]<<spc;
    }

//    fileclose
    return 0;
}
