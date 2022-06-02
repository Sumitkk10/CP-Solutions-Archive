#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long n, a[N], q[N], siz[N], components[N];

int find(int x){
    while(true){
        if(x == components[x])
            return x;
        components[x] = components[components[x]];
        x = components[x];
    }
}

void merge(int a, int b){
    int u = find(a), v = find(b);
    if(components[u] != v){
        components[u] = v;
        siz[v] += siz[u];
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        components[i] = i;
        siz[i] = 0;
    }
    for(int i = 1; i <= n; ++i)
        cin >> q[i];
    vector<ll> ans;
    ll mx = 0;
    ans.push_back(0);
    vector<bool>vis(n + 1, 0);
    for(int i = n; i >= 2; --i){
        siz[find(q[i])] += a[q[i]];
        if(vis[q[i] - 1] and vis[q[i] + 1]){
            merge(q[i], q[i] - 1);
            merge(q[i], q[i] + 1);
        }
        else if(vis[q[i] - 1])
            merge(q[i], q[i] - 1);
        else if(vis[q[i] + 1])
            merge(q[i], q[i] + 1);
        vis[q[i]] = true;
        mx = max(mx, siz[find(q[i])]);
        ans.push_back(mx);
    }
    reverse(ans.begin(), ans.end());
    for(auto k : ans)
        cout << k << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
