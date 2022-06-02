#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		char a[n][n];
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				cin >> a[i][j];
		ll dp[n][n];
		memset(dp, 0, sizeof(dp));
		ll ans = 0;
		for(int i = 0; i < n; ++i){
			int j = n - 1;
			while(a[i][j] == '.' && j >= 0){
				dp[i][j]++;
				--j;
			}
		}
		for(int i = 0; i < n; ++i){
			int j = n - 1;
			while(a[j][i] == '.' && j >= 0){
				dp[j][i]++;
				--j;
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				// cout << dp[i][j] << " ";
				ans += (dp[i][j] == 2);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
