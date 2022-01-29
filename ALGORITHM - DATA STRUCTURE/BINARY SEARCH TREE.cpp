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
class node
{
    public:
        ll x;
        node *left, *right;
};
node* create(ll v)
{
    node *tem=new node();
    tem->x=v;
    tem->left=NULL;
    tem->right=NULL;
    return tem;
}
class tree
{
    public:
        node *data;
        ll length;
        ll number;
        tree(){
            data=NULL;
            length=0;
            number=0;
        }

        node* tree_push(node *tem,ll v){
            if(tem==NULL)
                tem=create(v);
            else if(v<tem->x)
                tem->left=tree_push(tem->left,v);
            else if(v>tem->x)
                tem->right=tree_push(tem->right,v);
            return tem;
        }
        void push(ll v){ //INPUT_FUNCTION
            number++;
            data = tree_push(data,v);
        }

        node* tree_pre(node *tem,vector<ll> &svg){ //pre-order traverse
            if(tem==NULL) return tem;
            svg.push_back(tem->x); //PARENT
            tem->left=tree_pre(tem->left,svg); //LEFT
            tem->right=tree_pre(tem->right,svg); //RIGHT
            return tem;
        }
        node* tree_post(node *tem,vector<ll> &svg){ //post-order traverse
            if(tem==NULL) return tem;
            tem->left=tree_post(tem->left,svg); //LEFT
            tem->right=tree_post(tem->right,svg); //RIGHT
            svg.push_back(tem->x); //PARENT
            return tem;
        }
        node* tree_in(node *tem,vector<ll> &svg){ //in-order traverse
            if(tem==NULL) return tem;
            tem->left=tree_in(tem->left,svg);//LEFT
            svg.push_back(tem->x);//PARENT
            tem->right=tree_in(tem->right,svg);//RIGHT
            return tem;
        }
        void tree_level(node *tem,vector<ll> &svg){ //LEVEL_ORDER_TRAVERSE
            queue<node*> q;
            q.push(tem);
            while(q.empty()==false){
                node *f=q.front();
                svg.push_back(f->x);
                if(f->left!=NULL) q.push(f->left);
                if(f->right!=NULL) q.push(f->right);
                q.pop();
            }
        }
        vector<ll> traverse(ll flag){
            vector<ll> svg;
            if(flag==1) data=tree_pre(data,svg);
            else if(flag==2) data=tree_post(data,svg);
            else if(flag==3) data=tree_in(data,svg);
            else if(flag==4) tree_level(data,svg);
            return svg;
        }

        node* tree_mn(node *tem){ //MIN NODE OF A TREE
            while(tem->left!=NULL)
                tem=tem->left;
            return tem;
        }
        node* tree_mx(node *tem){ //MAX NODE OF A TREE
            while(tem->right!=NULL)
                tem=tem->right;
            return tem;
        }
        ll extreme(bool flag){
            node* tem;
            if(flag==false)
                tem=tree_mn(data);
            else if(flag==true)
                tem=tree_mx(data);
            return tem->x;
        }

        ll tree_update(node *tem){
            if(tem==NULL)
                return -1;
            ll left=1+tree_update(tem->left); //HEIGHT_OF_A_NODE
            ll right=1+tree_update(tem->right);
            return max(left,right);
        }
        ll update(){
            length=tree_update(data);
            return length;
        }

        node* tree_depth(node *tem,ll v,ll &d){ //FIND THE NODE AND DEPTH OF A GIVEN VALUE
            static ll i=-1;
            i++;
            if(tem==NULL || v==tem->x){
                d = tem==NULL? -1 : i;
                return tem;
            }
            else if(v<tem->x)
                return tree_depth(tem->left,v,d);
            else if(v>tem->x)
                return tree_depth(tem->right,v,d);
        }
        ll depth(ll v){
            ll d;
            tree_depth(data,v,d);
            return d;
        }
        ll height(ll v){
            ll d;
            tree_depth(data,v,d);
            return update()-d;
        }

        void tree_isBST(node *tem,bool &b){
            if(tem==NULL)
                return;
            else if(tem->left==NULL && tem->right==NULL)
                return;
            else if(tem->left!=NULL && tem->right!=NULL){
                ll x=tem->x;
                ll left=tem->left->x;
                ll right=tem->right->x;
                if(left<=x && x<right){
                    tree_isBST(tem->left,b);
                    tree_isBST(tem->right,b);
                }
                else
                    b=false;
            }
            else if(tem->left==NULL && tem->right!=NULL){
                ll x=tem->x;
                ll right=tem->right->x;
                if(x<right){
                    tree_isBST(tem->right,b);
                }
                else
                    b=false;
            }
            else if(tem->left!=NULL && tem->right==NULL){
                ll x=tem->x;
                ll left=tem->left->x;
                if(left<=x){
                    tree_isBST(tem->left,b);
                }
                else
                    b=false;
            }
        }
        bool isBST(){ //CHECKING IF BINARY TREE
            bool b=true;
            tree_isBST(data,b);
            return b;
        }

        node* tree_kill(node *tem,ll v){ //DELETE A NODE
            if(tem==NULL)
                return tem;
            else if(v<tem->x)
                tem->left=tree_kill(tem->left,v);
            else if(v>tem->x)
                tem->right=tree_kill(tem->right,v);
            else if(v==tem->x){
                if(tem->left==NULL && tem->right==NULL)
                    tem = NULL;
                else if(tem->left==NULL && tem->right!=NULL)
                    tem = tem->right;
                else if(tem->left!=NULL && tem->right==NULL)
                    tem = tem->left;
                else if(tem->left!=NULL && tem->right!=NULL){
                    node *suc = tree_mn(tem->right);
                    tem->x = suc->x;
                    tem->right = tree_kill(tem->right,tem->x);
                }
            }
            return tem;
        }
        void kill(ll v){
            data=tree_kill(data,v);
        }

        void range(ll v,ll &previous,ll &next){ //previous < value < next
            ll d;
            node *tem=tree_depth(data,v,d);
            node *why=tree_mx(tem->left);
            node *how=tree_mn(tem->right);
            previous=why->x;
            next=how->x;
        }
};
void print(vector<ll> svg)
{
    ll sze = svg.size();
    for(ll i=0; i<sze; i++)
        cout<<svg[i]<<spc;
    cout<<lne;
}
int main()
{
//    inout
//    fileopen

    tree t;
    vector<ll> ans, v={30,20,65,10,25,40,75,5,15,23,27,45,70,80,3,72};
    ll previous, next, sze=v.size();
    for(ll i=0; i<sze; i++)
        t.push(v[i]);

    ans = t.traverse(1); print(ans);
    ans = t.traverse(2); print(ans);
    ans = t.traverse(3); print(ans);
    ans = t.traverse(4); print(ans);

    cout<<t.extreme(false)<<lne;
    cout<<t.extreme(true)<<lne;

    cout<<boolalpha<<t.isBST()<<lne;

    cout<<t.depth(5)<<lne;
    cout<<t.height(5)<<lne;

    t.range(75,previous,next);
    cout<<previous<<spc<<next<<lne;

    t.kill(65); print(ans);

//    fileclose
    return 0;
}
//                                        30
//                            20                      65
//                    10              25      40              75
//                 5      15       23    27      45       70      80
//               3                                     72
