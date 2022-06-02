#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, m, k, ans, perimeter, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
vector<pair<int, int> > v(N);
map<pair<int, int>, bool> vis, patch;

void dfs(int x, int y){
	if(x < 1 or y < 1 or x > n or y > m)
		return;
	vis[{x, y}] = true;
	// cout << x << ' ' << y << endl;
	for(int i = 0; i < 4; ++i){
		int _x = x + dx[i], _y = y + dy[i];
		if(!patch[{_x, _y}])
			++perimeter;
	}
	for(int i = 0; i < 4; ++i){
		int _x = x + dx[i], _y = y + dy[i];
		if(!vis[{_x, _y}] and patch[{_x, _y}])
			dfs(_x, _y);
	}
}

void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= k; ++i){
		cin >> v[i].F >> v[i].S;
		patch[{v[i].F, v[i].S}] = true;
	}
	for(int i = 1; i <= k; ++i){
		if(!vis[{v[i].F, v[i].S}]){
			perimeter = 0;
			dfs(v[i].F, v[i].S);
			ans = max(ans, perimeter);
		}
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}