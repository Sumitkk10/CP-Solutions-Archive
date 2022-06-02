#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
string ans = "What are you doing at the end of the world? Are you busy? Will you save us?";
string a = "What are you doing while sending \"";
string b = "\"? Are you busy? Will you send \"";
string c = "\"?";
vector<ll> dp(N, 1e18 + 1);

char get(ll n, ll k){
	if(k >= dp[n])
		return '.';
	if(n == 0)
		return ans[k];
	if(k < a.size()) return a[k];
	if(k < a.size() + dp[n - 1]) return get(n - 1, k - a.size());
	if(k < a.size() + dp[n - 1] + b.size()) return b[k - a.size() - dp[n - 1]];
	if(k < a.size() + dp[n - 1] + b.size() + dp[n - 1]) return get(n - 1, k - a.size() - dp[n - 1] - b.size());
	if(k < a.size() + dp[n - 1] + b.size() + dp[n - 1] + c.size()) return c[k - a.size() - dp[n - 1] - b.size() - dp[n - 1]];
	return '.';
}

void solve(){
	dp[0] = ans.size();
	for(int i = 1; i < 60; ++i){
		ll k = (2 * dp[i - 1]) + a.size() + b.size() + c.size();
		dp[i] = min(k, (ll) 1e18 + 1);
	}
	int q;
	cin >> q;
	while(q--){
		ll n, k;
		cin >> n >> k;
		cout << get(n, k - 1);
	}
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
