#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
string s;
int k, n, g[30][30], dp[101][101][30];

long long go(int i, int left, int pre){
	if(left < 0)
		return INT_MIN;
	if(i == s.size())
		return 0;
	if(dp[i][left][pre] != -1)
		return dp[i][left][pre];
	long long int ans = INT_MIN;
	ans = max(ans, go(i + 1, left, s[i] - 'a') + g[pre][s[i] - 'a']);
	for(int j = 0; j < 26; ++j)
		ans = max(ans, go(i + 1, left - 1, j) + g[pre][j]);
	return dp[i][left][pre] = ans;
}

void solve(){
	memset(dp, -1, sizeof dp);
	cin >> s >> k >> n;
	for(int i = 0; i < n; ++i){
		char a, b;
		int c;
		cin >> a >> b >> c;
		g[a - 'a'][b - 'a'] = c;
	}
	cout << go(0, k, 29) << "\n";
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
