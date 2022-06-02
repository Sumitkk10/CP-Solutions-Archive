#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int n, q, a[N], bit[N], bit1[N], bit2[N];

ll upd(ll idx, ll val, int type){
    if(type == 1){
        while(idx <= n){
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }
    else if(type == 2){
        while(idx <= n){
            bit1[idx] += val;
            idx += (idx & -idx);
        }
    }
    else{
        while(idx <= n){
            bit2[idx] += val;
            idx += (idx & -idx);
        }
    }
}

ll get(ll idx, int type){
    ll sum = 0;
    if(type == 1){
        while(idx > 0){
            sum += bit[idx];
            idx -= (idx & -idx);
        }
    }
    else if(type == 2){
        while(idx > 0){
            sum += bit1[idx];
            idx -= (idx & -idx);
        }
    }
    else{
        while(idx > 0){
            sum += bit2[idx];
            idx -= (idx & -idx);
        }
    }
    return sum;
}

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            long long int l, r, val;
            cin >> l >> r >> val;
            upd(l, 1, 1);
            upd(r + 1, -1, 1);
            upd(l, (val - l)*(val - l), 2);
            upd(r + 1, -(val - l)*(val - l), 2);
            upd(l, 2*(val - l), 3);
            upd(r + 1, -2*(val - l), 3);
        }
        else{
            long long int i;
            cin >> i;   
            long long ans = a[i] + get(i, 1)*i*i + get(i, 2) + get(i, 3)*i;
            cout << ans << '\n';
        }
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
