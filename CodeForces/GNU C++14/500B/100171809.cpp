#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 301;
const int MOD = 1e9 + 7;
long long int ans;
int swaps[N][N], n;
bool vis[N];

bool dfs(int from, int to){
	if(from == to) return true;
	if(vis[from]) return false;
	vis[from] = true;
	for(int i = 1; i <= n; ++i)
		if(swaps[from][i])
			if(dfs(i, to))
				return true;
	return false;
}

void solve(){
	cin >> n;
	int pos[n + 1], a[n + 1];
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		pos[a[i]] = i;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			char x;
			cin >> x;
			swaps[i][j] = (x - '0');
		}
	}
	vector<int> ans(n + 1, -1);
	for(int i = 1; i <= n; ++i){
		int x = pos[i];
		for(int j = 1; j <= n; ++j){
			if(ans[j] != -1) continue;
			memset(vis, 0, sizeof(vis));
			if(dfs(x, j)){
				ans[j] = i;
				break;
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
