#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 5001;
const int MOD = 1e9 + 7;
long long int n, m, k, a[N], pre_sum[N], dp[N][N];

long long int go(int i, int cnt){
	if(cnt > k)
		return LLONG_MIN;
	if(i == n + 1){
		if(cnt == k)
			return 0;
		return LLONG_MIN;
	}
	if(dp[i][cnt] != -1)
		return dp[i][cnt];
	ll ans = LLONG_MIN;
	if(i + m - 1 <= n)
		ans = max(ans, go(i + m, cnt + 1) + pre_sum[i + m - 1] - pre_sum[i - 1]);
	ans = max(ans, go(i + 1, cnt));
	return dp[i][cnt] = ans;
}

int main(){
	fast;
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		pre_sum[i] = pre_sum[i - 1] + a[i];
	}
	cout << go(1, 0) << '\n';
	return 0;
}
