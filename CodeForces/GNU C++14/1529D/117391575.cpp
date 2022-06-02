#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 998244353 , N = 1e5 + 3;
int n;

void solve(){
	cin >> n;
	int dp[n + 1];
	memset(dp, 0, sizeof dp);
	for(int i = 1; i <= n; ++i)
	    for(int j = 2*i; j <= n; j += i)
	        dp[j]++;
	int cur = 1;
	for(int i = 1; i <= n; ++i){
	    dp[i] = (dp[i] + cur) % MOD;
	    cur = (cur + dp[i]) % MOD;
	}
	cout << dp[n] << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--) solve();
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}