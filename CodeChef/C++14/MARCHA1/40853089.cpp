#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, m, a[25], dp[25][N];

bool go(int i, int tar){
	if(i == n){
		if(tar == 0)
			return 1;
		return 0;
	}
	if(dp[i][tar] != -1)
		return dp[i][tar];
	bool what = 0;
	what |= go(i + 1, tar - a[i]);
	what |= go(i + 1, tar);
	return dp[i][tar] = what;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	memset(dp, -1, sizeof(dp));
	cout << (go(0, m) ? "Yes\n" : "No\n");
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
// 