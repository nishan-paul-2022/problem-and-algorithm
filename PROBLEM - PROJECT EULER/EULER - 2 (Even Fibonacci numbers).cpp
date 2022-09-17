///CUET-IRON-BAT
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define udouble unsigned double
#define pushb push_back
#define pushf push_front
#define popb pop_back
#define popf pop_front
#define mpair make_pair
#define tostring to_string
#define countbit(n) __builtin_popcount(n)
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

class bigint
{
    public:
        string a;
        ll sign;
        ll length(){return a.size();}
        bigint(){}
        bigint(string b){(*this)=b;}
        bigint inverseSign(){
            sign *= -1;
            return (*this);
        }
        bigint normalize(ll newSign){
            for(ll i=length()-1; i>0 && a[i]=='0'; i--)
                a.erase(a.begin()+i);
            sign = (length()==1 && a[0]=='0')? 1:newSign;
            return (*this);
        }
        bigint operator=(string b){
            a = b[0]=='-'? b.substr(1):b;
            reverse(a.begin(),a.end());
            this->normalize(b[0]=='-'? -1:1);
            return (*this);
        }
        bool operator<(bigint b){
            if(sign!=b.sign) return sign<b.sign;
            if(length()!=b.length())
                return sign==1? (length()<b.length()):(length()>b.length());
            for(ll i=length()-1; i>=0; i--)
                if(a[i]!=b.a[i])
                    return sign==1? (a[i]<b.a[i]):(a[i]>b.a[i]);
            return false;
        }
        bool operator==(bigint b){ return a==b.a && sign==b.sign;}
        bigint operator+(bigint b){
            if(sign!=b.sign) return (*this)-b.inverseSign();
            bigint c;
            for(ll i=0,carry=0; i<length() || i<b.length() || carry; i++){
                carry += (i<length()? a[i]-48 : 0) + (i<b.length()? b.a[i]-48 : 0);
                c.a += (carry%10 + 48);
                carry /= 10;
            }
            return c.normalize(sign);
        }
        bigint operator-(bigint b){
            if(sign!=b.sign) return (*this)+b.inverseSign();
            ll s=sign;
            sign = b.sign = 1;
            if((*this)<b) return ((b-(*this)).inverseSign()).normalize(-s);
            bigint c;
            for(ll i=0, borrow=0; i<length(); i++){
                borrow = a[i]-borrow-(i<b.length()? b.a[i]:48);
                c.a += borrow>=0? borrow+48 : borrow+58;
                borrow = borrow>=0? 0:1;
            }
            return c.normalize(s);
        }
        bigint operator*(bigint b){
            bigint c("0");
            for(ll i=0,k=a[i]-48; i<length(); i++,k=a[i]-48){
                while(k--) c=c+b;
                b.a.insert(b.a.begin(),'0');
            }
            return c.normalize(sign*b.sign);
        }
        bigint operator/(bigint b){
            if(b.length()==1 && b.a[0]=='0') b.a[0] /= (b.a[0]-48);
            bigint c("0"),d;
            for(ll j=0; j<length(); j++) d.a+="0";
            ll dSign=sign*b.sign;
            b.sign=1;
            for(ll i=length()-1; i>=0; i--){
                c.a.insert(c.a.begin(),'0');
                c=c+a.substr(i,1);
                while(!(c<b)){
                    c=c-b;
                    d.a[i]++;
                }
            }
            return d.normalize(dSign);
        }
        bigint operator%(bigint b){
            if(b.length()==1 && b.a[0]=='0') b.a[0] /= (b.a[0]-48);
            bigint c("0");
            b.sign=1;
            for(ll i=length()-1; i>=0; i--){
                c.a.insert(c.a.begin(),'0');
                c=c+a.substr(i,1);
                while(!(c<b)) c=c-b;
            }
            return c.normalize(sign);
        }
};
istream& operator>>(istream &in,bigint &x){
    string s;
    cin>>s;
    x=s;
    return in;
}
ostream& operator<<(ostream &out,bigint x){
    reverse(x.a.begin(),x.a.end());
    if(x.sign==-1) x.a="-"+x.a;
    out<<x.a;
    return out;
}
string multiply(string a,ll b){
    reverse(a.begin(),a.end());
    ll carry=0, sze=a.size();
    for(ll i=0; i<sze; i++){
        carry += (a[i]-48)*b;
        a[i] = (carry%10 + 48);
        carry /= 10;
    }
    while(carry){
        a += (carry%10 + 48);
        carry /= 10;
    }
    reverse(a.begin(),a.end());
    return a;
}
string division(string s,ll n,ll &r){
    string t;
    r=0;
    ll sze=s.size();
    for(ll i=0; i<sze; i++){
        ll a=10*r+(s[i]-'0');
        ll b=a/n;
        r=a%n;
        if(b) t+=to_string(b);
    }
    return t;
}

int main()
{
//    inout
    fileopen

    bigint n;
    cin >> n;
    string a="2", b="0", c="1";
    bigint v[2];
    v[0] = c, v[1] = c;
    bigint ans = b;
    for(ll i = 0; v[1] < n || v[1] == n; i++) {
        bigint value = v[1] + v[0];
        v[0] = v[1];
        v[1] = value;
        if( value % a == b )
            ans = ans + value;
    }
    cout << ans << lne;

    fileclose
    return 0;
}

