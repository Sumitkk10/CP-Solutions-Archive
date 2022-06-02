#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 705;
const int MOD = 1e9 + 7;
int n, k, val[N], b[N], dp[N][N];

ll go(int str, int end){
	if(str >= end)
		return dp[str][end] = 0;
	if(dp[str][end] != -1)
		return dp[str][end];
	ll ans = 0;
	for(int i = str + 1; i <= end; ++i)
		if(b[str] + k == b[i])
			ans = max(ans, val[str] + val[i] + go(str + 1, i - 1) + go(i + 1, end));
	ans = max(ans, go(str + 1, end));
	return dp[str][end] = ans;
}

int main(){
	fast;
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> val[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	cout << go(0, n - 1);
	return 0;
}
