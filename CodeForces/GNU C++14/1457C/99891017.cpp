#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, p, k;
	cin >> n >> p >> k;
	string ss;
	cin >> ss;
	int x, y;
	cin >> x >> y; // x is the cost for adding a platform anywhere, and, y is the cost for removing 1st platform.
	long long int dp[n];
	// dp[i] denotes minimum no of moves to cross i if I place at the ith level.
	for(int i = p - 1; i < n; ++i){
		if(!(ss[i] - '0'))
			dp[i] = ((i - p + 1) * y) + x;
		else 
			dp[i] = (i - p + 1) * y;
		if(i - k >= p - 1){
			if(!(ss[i] - '0')) dp[i] = min(dp[i], dp[i - k] + x);
			else dp[i] = min(dp[i], dp[i - k]);
		}
	}
	long long int ans = LLONG_MAX;
	for(int i = n - 1; i >= max(p - 1, n - k); --i)
		ans = min(ans, dp[i]);
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
