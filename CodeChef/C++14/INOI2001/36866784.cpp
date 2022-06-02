#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e5 + 3;
vii graph[N], even, odd;
bool vis[N];
ll siz, mn = 1e9, mx, ans, n, m;

void dfs(ll n){
    vis[n] = true;
    ++siz;
    mn = min(mn, n);
    mx = max(mx, n);
    for(auto i : graph[n]){
        if(vis[i] == false)
            dfs(i);
    }
}

void dpt(ll n, ll dptt){
    vis[n] = true;
    ans += dptt;
    for(auto i : graph[n]){
        if(vis[i] == false)
            dpt(i, dptt + 1);
    }
}

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < m; ++i){
            ll x, y;
            cin >> x >> y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        for(int i = 1; i <= n; ++i){
            if(vis[i] == false){
                dfs(i);
                if(siz % 2 == 0 && siz != 0) 
                    even.pb(mn);
                else if(siz % 2 == 1 && siz != 0)
                    odd.pb(mx);
                mx = 0;
                mn = 1e9;
                siz = 0;
            }
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < even.size(); ++i)
            dpt(even[i], 1);
        memset(vis, 0, sizeof(vis));
        cout << ans << " ";
        ans = 0;
        for(int i = 0; i < odd.size(); ++i)
            dpt(odd[i], 1);
        cout << ans << "\n";
        for(int i = 1; i <= N; ++i)
            graph[i].clear();
        even.clear();
        odd.clear();
        memset(vis, 0, sizeof(vis));
        ans = 0;
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}