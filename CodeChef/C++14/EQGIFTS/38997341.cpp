#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 152, M = 45002;
const int MOD = 1e9 + 7;
ll n, a[N], b[N], dp[N][M], sum;

ll solve(int i, long long int sum1){
	if(i > n) return 0;
	if(dp[i][sum1] != -1) return dp[i][sum1];
	if(i == n)
		return abs(sum1 - (sum - sum1));
	ll mn = INT_MAX;
	mn = min(mn, solve(i + 1, sum1 + a[i]));
	mn = min(mn, solve(i + 1, sum1 + b[i]));
	return dp[i][sum1] = mn;
}

int main(){
	fast;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i];
		sum += a[i];
		sum += b[i];
	}
	cout << solve(0, 0) << "\n";
	return 0;
}
