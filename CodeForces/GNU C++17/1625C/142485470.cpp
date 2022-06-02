#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, len, k, dis[N], speed[N], dp[501][501];

int go(int i, int left){
	if(i == n)
		return 0;
	if(dp[i][left] != -1)
		return dp[i][left];
	int ans = INT_MAX;
	for(int j = i + 1; j <= n; ++j){
		if(j - i - 1 > left) break;
		ans = min(ans, go(j, left - (j - i - 1)) + speed[i] * (dis[j] - dis[i]));
	}
	return dp[i][left] = ans;
}

void solve(){
	memset(dp, -1, sizeof dp);
	cin >> n >> len >> k;
	for(int i = 0; i < n; ++i)
		cin >> dis[i];
	for(int i = 0; i < n; ++i)
		cin >> speed[i];
	dis[n] = len;
	cout << go(0, k) << '\n';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
    	solve();
	return 0;
}