#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 500;
const int MOD = 1e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;
	int a[n], dp[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	dp[0] = 1;
	for(int i = 1; i < n; ++i){
		if(abs(a[i - 1] - a[i]) <= k)
			dp[i] = dp[i - 1] + 1;
		else
			dp[i] = 1;
	}
	cout << (*max_element(dp, dp + n) == 1 ? -1 : *max_element(dp, dp + n)) << "\n";
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
