#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0;
	int dp[n + 1];
	for(int i = 0; i <= n; ++i)
		dp[i] = INT_MIN;
	for(int i = 0; i < n; ++i){
		int ok = ans;
		ans = max(ans, dp[a[i]] + 1);
		dp[a[i]] = max(dp[a[i]], ok + 1);
	}
	cout << n - ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
// 