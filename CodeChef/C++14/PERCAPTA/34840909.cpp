#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 2e5 + 3;
vii graph[N], ans1;
bool vis[N];

void dfs(ll n){
	vis[n] = true;
	ans1.pb(n);
	for(int i = 0; i < graph[n].size(); ++i){
		if(vis[graph[n][i]] == false)
			dfs(graph[n][i]);
	}
}

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
    	ll n, m;
    	cin >> n >> m;
    	ll a[n], b[n];
    	for(int i = 0; i < n; ++i)
    		cin >> a[i];
    	for(int i = 0; i < n; ++i)
    		cin >> b[i];
    	for(int i = 0; i < m; ++i){
    		ll x, y;
    		cin >> x >> y;
    		--x;
    		--y;
    		graph[x].pb(y);
    		graph[y].pb(x);
    	}
    	ll mx = 0;
    	vii ans;
    	for(int i = 0; i < n; ++i)
    		mx = max(mx, a[i]/b[i]);
 		for(int i = 0; i < n; ++i){
 			ll k = a[i]/b[i];
 			if(k != mx)
 				vis[i] = true;
 		}
 		for(int i = 0; i < n; ++i){
 			if(vis[i] == false){
 				dfs(i);
 				if(ans.size() < ans1.size()) 
 					ans = ans1;
 				ans1.clear();
 			}
 		}
 		cout << ans.size() << endl;
 		for(int i = 0; i < ans.size(); ++i)
 			cout << ans[i] + 1 << " ";
 		cout << endl;
 		for(int i = 0; i < N; ++i)
 			graph[i].clear();
 		ans.clear();
 		for(int i = 0; i < N; ++i)
 			vis[i] = false;
    }
    return 0;
}