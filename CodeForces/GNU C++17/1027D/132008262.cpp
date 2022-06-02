#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int n, c[N], a[N], vis[N], parent[N], ans, mn = INT_MAX;
bool ok;

void dfs(int node, int p){
    vis[node] = 1;
    parent[node] = p;
    if(a[node] == node){
        ok = 1;
        ans += c[node];
    }
    if(!vis[a[node]])
        dfs(a[node], node);
    else if(vis[a[node]] == 1){
        int cur = node, tar = a[node];
        while(cur ^ tar){
            mn = min(mn, c[cur]);
            cur = parent[cur];
        }
        mn = min(mn, c[tar]);
    }
    else
        mn = 0;
    vis[node] = 2;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            dfs(i, 0);
            if(!ok)
                ans += mn;
            ok = 0;
            mn = INT_MAX;
        }
    }
    cout << ans << "\n";
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    int t = 1;
    while(t--)
        solve();
	return 0;
}
