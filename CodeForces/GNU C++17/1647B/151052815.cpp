#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e2 + 5, MOD = 1e9 + 7;
int n, m, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool a[N][N], vis[N][N];
int mn_i, mx_i, mn_j, mx_j, pre[N][N];

void dfs(int i, int j){
	if(vis[i][j] or i < 1 or j < 1 or i > n  or j > m or !a[i][j]) 
		return;
	vis[i][j] = true;
	mn_i = min(mn_i, i);
	mx_i = max(mx_i, i);
	mn_j = min(mn_j, j);
	mx_j = max(mx_j, j);
	for(int k = 0; k < 4; ++k)
		dfs(i + dx[k], j + dy[k]);
}

void solve(){
	cin >> n >> m;
	memset(vis, 0, sizeof vis);
	memset(pre, 0, sizeof pre);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			char x;
			cin >> x;
			a[i][j] = (x == '1');
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
		}
	}
	bool ans = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(a[i][j] and !vis[i][j]){
				mx_j = 0;
				mn_j = INT_MAX;
				mx_i = 0;
				mn_i = INT_MAX;
				dfs(i, j);
				// cout << i << ' ' << j << endl;
				// cout << mx_i << ' ' << mn_i << ' ' << mx_j << ' ' << mn_j << endl;
				int area = (mx_i - mn_i + 1) * (mx_j - mn_j + 1);
				int actual_area = (pre[mx_i][mx_j] - pre[mn_i - 1][mx_j] - pre[mx_i][mn_j - 1] + pre[mn_i - 1][mn_j - 1]);
				ans &= (area == actual_area);
			}
		}
	}
	cout << (ans ? "Yes\n" : "No\n");
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
1
3 3
110
111
000
*/