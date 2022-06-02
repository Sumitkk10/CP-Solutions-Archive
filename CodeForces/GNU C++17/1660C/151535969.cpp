#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	int dp[s.size() + 1];
	dp[0] = 0;
	dp[1] = 0;
	int pre[30];
	memset(pre, -1, sizeof pre);
	pre[s[1] - 'a'] = 1;
	for(int i = 2; i <= n; ++i){
		dp[i] = dp[i - 1];
		if(pre[s[i] - 'a'] != -1)
			dp[i] = max(dp[pre[s[i] - 'a'] - 1] + 2, dp[i]);
		pre[s[i] - 'a'] = i;
	}
	cout << n - dp[n] << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}