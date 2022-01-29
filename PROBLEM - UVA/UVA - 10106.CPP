///CUET-IRON-BAT
///"To Cut Down A Tree In Five Minutes, Spend Three Minutes Sharpening Your Axe"
///"A Master Has Failed More Times Than A Newbie Has Even Tried."
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define vl vector<long long>
#define vlit vector<long long>::iterator
#define vlvl vector< vector<long long> >
#define vlvlit vector< vector<long long> >::iterator
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
#define pls pair<ll,string>
#define vpls vector< pair<ll,string> >
#define vplsit vector< pair<ll,string> >::iterator
#define psl pair<string,ll>
#define vpsl vector< pair<string,ll> >
#define vpslit vector< pair<string,ll> >::iterator
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
            for(ll i=0,carry=0; i<length() | i<b.length() || carry; i++){
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
int main()
{
//    inout
//    fileopen
    bigint x,y;
    while(cin>>x>>y)
        cout<<(x*y)<<lne;
//    fileclose
    return 0;
}
