#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N];

void solve(){
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int dp[n], ans = a[0];
	dp[0] = a[0];
	for(int i = 1; i < n; ++i){
		int mx = 0;
		for(int j = 0; j < i; ++j){
			if(a[j] < a[i])
				mx = max(mx, dp[j]);
		}
		dp[i] = mx + a[i];
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
