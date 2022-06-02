#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e6 + 5;
const int MOD = 1e9 + 7;
ll n, dp[N];
string s;

ll go(ll i){
	if(i == n) return 1;
	if(s[i] == '0') return 0;
	if(dp[i] != -1) return dp[i];
	ll cnt = 0;
	cnt = (cnt + go(i + 1)) % MOD;
	cnt %= MOD;
	if(i + 1 < n){
		if(((s[i] - '0')*10 + (s[i + 1] - '0')) <= 26)
			cnt = (cnt + go(i + 2)) % MOD;
	} 
	cnt %= MOD;
	return dp[i] = cnt;
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		cin >> s;
		n = s.size();
		for(int i = 0; i <= n; ++i) dp[i] = -1;
		cout << go(0) << "\n";
	}
	return 0;
}
