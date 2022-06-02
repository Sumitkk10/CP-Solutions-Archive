#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 5e3 + 5;
int n, a[N], dp[N][N];
vector<int> one, zero;

long long go(int i, int j){
	// i denotes the pos in one;
	// j denotes the pos in zero;
	if(i == one.size())
		return 0;
	if(j == zero.size())
		return INT_MAX;
	if(dp[i][j] != -1)
	    return dp[i][j];
	long long ans = INT_MAX;
	ans = min(ans, go(i + 1, j + 1) + abs(one[i] - zero[j]));
	ans = min(ans, go(i, j + 1));
	return dp[i][j] = ans;
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i] == 1)
			one.push_back(i);
		else
			zero.push_back(i);
	}
	memset(dp, -1, sizeof dp);
	cout << go(0, 0) << '\n';
}

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}