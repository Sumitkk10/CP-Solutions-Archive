#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int component[N], seg[N];

int find(int a){
    while(true){
        if(a == component[a])
            return a;
        component[a] = component[component[a]];
        a = component[a];
    }
}

void merge(int a, int b){
    int u = find(a), v = find(b);
    component[u] = v;
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        component[i] = i;
        seg[i] = i + 1;
    }
    while(q--){
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1)
            merge(l, r);
        else if(type == 2){
            int pre = l;
            while(pre < r){
                if(pre + 1 <= r)
                    merge(pre, pre + 1);
                int cur = seg[pre];
                seg[pre] = r;
                pre = cur;
            }
        }
        else
            cout << (find(l) == find(r) ? "YES\n" : "NO\n");
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
