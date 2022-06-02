#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, a[N], dp[104][3];

long long go(int i, int pre){
	if(i == n)
		return 0;
	if(dp[i][pre] != -1)
		return dp[i][pre];
	long long ans = INT_MAX;
	ans = min(ans, go(i + 1, 0) + 1);
	if(a[i] == 1){
		if(pre != 1)
			ans = min(ans, go(i + 1, 1));
	}
	if(a[i] == 2){
		if(pre != 2)
			ans = min(ans, go(i + 1, 2));
	}
	if(a[i] == 3){
		if(pre != 2)
			ans = min(ans, go(i + 1, 2));
		if(pre != 1)
			ans = min(ans, go(i + 1, 1));
	}
	return dp[i][pre] = ans;
}

void solve(){
	memset(dp, -1, sizeof dp);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	cout << go(0, 0) << '\n';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}