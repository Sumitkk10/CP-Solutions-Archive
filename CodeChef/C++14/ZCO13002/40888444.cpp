#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 500 + 5;
const int MOD = 1e9 + 7;
bool vis[N][N];

void solve(){
	int n, m;
	cin >> n >> m;
	int a[n][n];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> a[i][j];
	while(m--){
		int x, y, k;
		cin >> x >> y >> k;
		--x, --y;
		vis[x][y] = true;
		int kk = k, ct = 1;
		for(int j = y + 1; j < n; ++j){
			if(kk <= 0) break;
			vis[x][j] = true;
			--kk;
		}
		kk = k;
		for(int j = y - 1; j >= 0; --j){
			if(kk <= 0) break;
			vis[x][j] = true;
			--kk;
		}
		kk = k;
		int i = x - 1;
		while(i >= 0 and kk > 0){
			vis[i][y] = true;
			int j = y + 1, kkk = --kk;
			while(kkk > 0 and j < n){
				vis[i][j] = true;
				++j, --kkk;
			}
			kkk = kk, j = y - 1;
			while(j >= 0 and kkk > 0){
				vis[i][j] = true;
				--j, --kkk;
			}
			--i;
		}
		kk = k, ct = 1;
		i = x + 1;
		while(i < n and kk > 0){
			vis[i][y] = true;
			int j = y + 1, kkk = --kk;
			while(kkk > 0 and j < n){
				vis[i][j] = true;
				++j, --kkk;
			}
			kkk = kk, j = y - 1;
			while(j >= 0 and kkk > 0){
				vis[i][j] = true;
				--j, --kkk;
			}
			++i;
		}
	}
	/*
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cout << vis[i][j] << ' ';
		cout << endl;
	}
	*/
	int dp[n][n];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			dp[i][j] = INT_MIN;
	if(vis[0][0])
		dp[0][0] = a[0][0];
	for(int i = 1; i < n; ++i){
		if(vis[i][0]){
			if(dp[i - 1][0] == INT_MIN) continue;
			dp[i][0] = a[i][0] + dp[i - 1][0];
		}
	}
	for(int j = 1; j < n; ++j){
		if(vis[0][j]){
			if(dp[0][j - 1] == INT_MIN) continue;
			dp[0][j] = a[0][j] + dp[0][j - 1];
		}
	}
	for(int i = 1; i < n; ++i){
		for(int j = 1; j < n; ++j){
			if(vis[i][j]){
				if(dp[i - 1][j] == INT_MIN and dp[i][j - 1] == INT_MIN) continue;
				else if(dp[i - 1][j] == INT_MIN and dp[i][j - 1] != INT_MIN) dp[i][j] = a[i][j] + dp[i][j - 1];
				else if(dp[i - 1][j] != INT_MIN and dp[i][j - 1] == INT_MIN) dp[i][j] = a[i][j] + dp[i - 1][j]; 
				else dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	if(dp[n - 1][n - 1] == INT_MIN){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << dp[n - 1][n - 1] << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
