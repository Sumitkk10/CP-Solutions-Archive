#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 5e5 + 3;
vector<ll> tree[N];
ll p[N], tar, dpt[N];
bool vis[N];

void dptt(ll n, ll dpttt){
    dpt[n] = dpttt;
    vis[n] = true;
    for(auto i : tree[n]){
        if(vis[i] == false)
            dptt(i, dpttt + 1);
    }
}

void dfs(int n){
    p[n] += tar;
    for(auto i : tree[n]){
        if(dpt[n] < dpt[i])
            dfs(i);
    }
}

int main(){
    fast;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    dptt(1, 0);
    for(int i = 0; i < m; ++i){
        ll x;
        cin >> x >> tar;
        dfs(x);
    }
    for(int i = 1; i <= n; ++i) cout << p[i] << " ";
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}