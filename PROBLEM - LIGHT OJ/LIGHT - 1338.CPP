///CUET-IRON-BAT
///"To Cut Down A Tree In Five Minutes, Spend Three Minutes Sharpening Your Axe"
///"A Master Has Failed More Times Than A Newbie Has Even Tried."
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vlit vector<long long>::iterator
#define vvl vector< vector<long long> >
#define vvlit vector< vector<long long> >::iterator
#define vul vector<unsigned long long>
#define vulit vector<unsigned long long>::iterator
#define vdou vector<double>
#define vdouit vector<double>::iterator
#define vstr vector<string>
#define vstrit vector<string>::iterator
#define vbol vector<bool>
#define vbolit vector<bool>::iterator
#define pll pair<long long,long long>
#define vpll vector< pair<long long,long long> >
#define vpllit vector< pair<long long,long long> >::iterator
#define pls pair<long long,string>
#define vpls vector< pair<long long,string> >
#define vplsit vector< pair<long long,string> >::iterator
#define psl pair<string,long long>
#define vpsl vector< pair<string,long long> >
#define vpslit vector< pair<string,long long> >::iterator
#define vvpll vector< vector< pair<long long,long long> > >
#define vvpllit vector< vector< pair<long long,long long> > >::iterator
#define vomg vector<omg>
#define vomgit vector<omg>::iterator
#define vvomg vector< vector<omg> >
#define vvomgit vector< vector<omg> >::iterator
#define mll map<long long,long long>
#define mllit map<long long,long long>::iterator
#define msl map<string,long long>
#define mslit map<string,long long>::iterator
#define mls map<long long,string>
#define mlsit map<long long,string>::iterator
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
#define inout ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileopen system("input.txt"); freopen("input.txt","r",stdin); FILE *f=freopen("output.txt","w",stdout);
#define fileclose fclose(f); system("output.txt");
using namespace std;
inline string small(string s){/// STRING LENGTH
    string sx;
    ll sze=s.size();
    for(ll i=0; i<sze; i++){
        if(s[i]>='A' && s[i]<='Z')
            sx+=(s[i]+32);
        else if(s[i]>='a' && s[i]<='z')
            sx+=s[i];
    }
    return sx;
}
inline string capital(string s){/// STRING LENGTH
    ll sze=s.size();
    for(ll i=0; i<sze; i++)
        if(s[i]>='a' && s[i]<='z')
            s[i]-=32;
    return s;
}
inline map<string,ll> word(string s,ll &cnt){/// STRING LENGTH
    ll sze=s.size();
    map<string,ll> m;
    string t="";
    for(ll i=0; i<=sze; i++){
        if(i==sze || s[i]==32){
            m[t]++;
            cnt++;
            t="";
        }
        else t+=s[i];
    }
    return m;
}
inline vector<string> permu(string s){/// N!.N.LOG(N)
    ll sze=s.size(), ans[sze+1], x,y,z;
    ans[0]=1;
    for(ll i=1; i<=sze; i++)
        ans[i]=i*ans[i-1];
    map<char,ll> m;
    for(ll i=0; i<sze; i++)
        m[s[i]]++;
    for(map<char,ll>::iterator it=m.begin(); it!=m.end(); it++)
        if(it->second>1) ans[sze]/=it->second;
    vector<string> v;
    sort(s.begin(),s.end());
    v.push_back(s);
    for(ll i=1; i<ans[sze]; i++){
        ll j,idx=-1;
        for(j=sze-2; j>=0; j--){
            if(s[j]<s[j+1])
                break;
        }
        for(ll k=j+1; k<sze; k++){
            if(s[j]<s[k]){
                if(idx==-1) idx=k;
                else idx= s[k]<s[idx]?k:idx;
            }
        }
        swap(s[j],s[idx]);
        sort(s.begin()+j+1,s.end());
        v.push_back(s);
    }
    return v;
}
inline void subsequence(string s, vector<string> &v, map<ll,vector<string>> &m){/// LENGTH.(2^LENGTH)
    ll sze=s.length();
    ll num=1<<sze;
    for(ll i=1; i<=num-1; i++){
        string tem="";
        ll val=i, j=0;
        while(val){
            if(val%2 != 0) tem+=s[j];
            val/=2;
            j++;
        }
        v.push_back(tem);
    }
    sort(v.begin(),v.end());
    for(auto i:v)
        m[i.length()].push_back(i);
}
inline vector<string> substring(string s){/// N^2
    vector<string> v;
    vector<string>::iterator it;
    ll sze=s.size(), k=1, ans=0;
    for(ll i=sze; i>=1; i--){
        for(ll j=0; j<k; j++){
            string tem=s.substr(j,i);
//            it=find(v.begin(),v.end(),tem);
//            if(it==v.end())
                v.push_back(tem);
        }
        k++;
    }
    return v;
}
int main()
{
//    inout
//    fileopen
    ll tst;
    cin>>tst;
    getchar();
    for(ll cs=1; cs<=tst; cs++){
        string s,t;
        getline(cin,s,lne); getline(cin,t,lne);
        s=small(s); t=small(t);
        sort(s.begin(),s.end()); sort(t.begin(),t.end());
        cout<<"Case "<<cs<<": "<<(s==t?"Yes":"No")<<lne;
    }
//    fileclose
    return 0;
}
