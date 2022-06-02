#include <bits/stdc++.h>
#define ll long long int    
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e5 + 2;
vector<ll> a(N), tree[N];
ll s[N], ans = INT_MIN;
bool vis[N];

 void dfs(ll node){
    vis[node] = true;
    ll mn = INT_MAX;
    for(int i = 0; i < tree[node].size(); i++){
        if(vis[tree[node][i]] == false){
            dfs(tree[node][i]);
            mn = min(s[tree[node][i]], mn);
        }
    }
    ans = max(ans, a[node] - mn);
    s[node] = min(mn, a[node]);
}

int main() {
    fast;
    ll n, root;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i){
        ll x;
        cin >> x;
        if(x == -1){
            root = i;
            continue;
        }
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    dfs(root);
    cout << ans;
    return 0;
}