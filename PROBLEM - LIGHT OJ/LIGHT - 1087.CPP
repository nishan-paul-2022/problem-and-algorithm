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
 
class data {
    public:
        ll sum, val, pos;
};
 
void update(ll node, ll low, ll high, ll index, ll val, ll vis, data tree[]) {

    if(low==high) {
        tree[node].sum = vis;
        tree[node].val = val;
        tree[node].pos = index;
        return;
    }

    ll mid = (low+high)/2;
    ll left = 2*node;
    ll right = 2*node+1;

    if(index<=mid) 
        update(left, low, mid, index, val, vis, tree);
    else
        update(right, mid+1, high, index, val, vis, tree);

    tree[node].sum = tree[left].sum + tree[right].sum;
}

ll query(ll node, ll low, ll high, ll index, data tree[]) {

    tree[node].sum--;

    if(low==high) 
        return tree[node].val;

    ll mid = (low+high)/2;
    ll left = 2*node;
    ll right = 2*node+1;

    if(index<=tree[left].sum) 
        return query(left, low, mid, index, tree);
    else
        return query(right, mid+1, high, index-tree[left].sum, tree);
}

int main()
{
    // fileopen

    ll t;
    scanf("%lld", &t);

    for(ll z=1; z<=t; z++) {

        getchar();

        ll n, q;
        scanf("%lld %lld", &n, &q);

        ll limit = n+q; // It's the highest limit if in every query there is "a" operation
        data tree[10000];

        for(ll i=1; i<=n; i++) {
            ll x;
            scanf("%lld", &x);
            update(1, 1, limit, i, x, 1, tree);
        }

        printf("Case %lld:\n", z);

        for(ll i=1; i<=q; i++) {
            ll x;
            char c;
            scanf("%s %lld", &c, &x);

            if(c=='a') {
                n++;
                update(1, 1, limit, n, x, 1, tree);
            }
            else {
                if( tree[1].sum < x )
                    printf("none\n");
                else
                    printf("%lld\n", query(1, 1, limit, x, tree));
            }
        }

        memset(tree, 0, sizeof(tree));
    }

    // fileclose
    return 0;
}


// #include<bits/stdc++.h>
// #define mx 200005
// #define LL long long
// #define pb push_back
// using namespace std;

// int arr[mx], A[mx], tree[mx * 4];

// void init(int node, int b, int e) {

//     if (b == e) {
//         tree[node] = arr[b];
//         return;
//     }

//     int Left = node * 2;
//     int Right = node * 2 + 1;
//     int mid = (b + e) / 2;
//     init(Left, b, mid);
//     init(Right, mid + 1, e);
//     tree[node] = tree[Left] + tree[Right];
// }

// int query(int node, int b, int e, int i, int j) { /* takes O(logn) time */

//     if (i > e || j < b)
//         return 0; /* gone outside */
//     if (b >= i && e <= j)
//         return tree[node]; /* relevant segment */

//     int Left = node * 2; /* should be divided more */
//     int Right = node * 2 + 1;
//     int mid = (b + e) / 2;
//     int p1 = query(Left, b, mid, i, j);
//     int p2 = query(Right, mid + 1, e, i, j);

//     return p1 + p2;
// }

// void update(int node, int b, int e, int i, int newvalue) { /* takes O(logn) time */

//     if (i > e || i < b)
//         return; /* gone outside */

//     if (b >= i && e <= i) { /* relevant segment */
//         tree[node] = newvalue; /* update by new value */
//         return;
//     }

//     int Left = node * 2; /* should be divided more */
//     int Right = node * 2 + 1;
//     int mid = (b + e) / 2;
//     update(Left, b, mid, i, newvalue);
//     update(Right, mid + 1, e, i, newvalue);
//     tree[node] = tree[Left] + tree[Right];
// }

// int main()
// {
//     int n, q, t;
//     scanf("%d",&t);

//     for(int tt=1; tt<=t; tt++) {

//         scanf("%d %d", &n, &q);

//         memset(arr, 0, sizeof(arr));

//         for(int i=1; i<=n; i++) {
//             scanf("%d",&A[i]);
//             arr[i] = 1; 
//         }

//         getchar();

//         int last = 2*n;
//         init(1, 1, last);
//         printf("Case %d:\n", tt);

//         while(q--) {
//             char ch;
//             int pos;
//             scanf("%c %d", &ch, &pos);
//             getchar();

//             if(ch=='c') {

//                 int lo = 1, hi = n, mid, ans = 0;

//                 for(int step=1; step<=20; step++) {

//                     mid = (lo+hi)/2;
//                     int j = query(1, 1, last, 1, mid);

//                     if(j>=pos) {
//                         hi = mid-1;
//                         ans = mid;
//                     }
//                     else 
//                         lo = mid+1;
//                 }

//                 if(ans) { 
//                     printf("%d\n", A[ans]); 
//                     update(1, 1, last, ans, 0); 
//                 }
//                 else 
//                     printf("none\n");
//             }
//             else {
//                 n++;
//                 A[n] = pos;
//                 update(1, 1, last, n, 1);
//             }
//         }
//     }
// }