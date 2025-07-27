
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
using ll = long long;
 
class data {
    public:
        ll sum, val, pos;
};

void update(ll node, ll low, ll high, ll index, ll val, ll vis, ::data tree_data[]) {

    if(low==high) {
        tree_data[node].sum = vis;
        tree_data[node].val = val;
        tree_data[node].pos = index;
        return;
    }

    ll mid = (low+high)/2;
    ll left = 2*node;
    ll right = 2*node+1;

    if(index<=mid) 
        update(left, low, mid, index, val, vis, tree_data);
    else
        update(right, mid+1, high, index, val, vis, tree_data);

    tree_data[node].sum = tree_data[left].sum + tree_data[right].sum;
}

ll query(ll node, ll low, ll high, ll index, ::data tree_data[]) {

    tree_data[node].sum--;

    if(low==high) 
        return tree_data[node].val;

    ll mid = (low+high)/2;
    ll left = 2*node;
    ll right = 2*node+1;

    if(index<=tree_data[left].sum) 
        return query(left, low, mid, index, tree_data);
    else
        return query(right, mid+1, high, index-tree_data[left].sum, tree_data);
}

int main()
{
    ll t;
    cin >> t;
    cin.ignore();

    for(ll z=1; z<=t; z++) {
        // Skip the blank line before each test case
        if(z > 1) cin.ignore();

        ll n, q;
        cin >> n >> q;

        ll limit = n+q;
        std::vector<::data> tree_arr(4 * limit + 10);

        for(ll i=1; i<=n; i++) {
            ll x;
            cin >> x;
            update(1, 1, limit, i, x, 1, tree_arr.data());
        }

        cout << "Case " << z << ":\n";

        for(ll i=1; i<=q; i++) {
            string op;
            ll x;
            cin >> op >> x;

            if(op == "a") {
                n++;
                update(1, 1, limit, n, x, 1, tree_arr.data());
            }
            else {
                if(tree_arr[1].sum < x)
                    cout << "none\n";
                else
                    cout << query(1, 1, limit, x, tree_arr.data()) << "\n";
            }
        }
    }

    return 0;
}
