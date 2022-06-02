#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 102, K = 1e5 + 6;
const int MOD = 1e9 + 7;
int n, taste[N], calories[N], dp[N][100000], k;

long long int go(int i, int d){
	if(i < 0){
		return (!d ? d : -(K << 10));
	}
	if(dp[i][d + K] != -1) return dp[i][d + K];
	int mx = -INT_MAX;
	mx = max(mx, (int) go(i - 1, d + taste[i] - calories[i]*k) + taste[i]);
	mx = max(mx, (int) go(i - 1, d));
	return dp[i][d + K] = mx;
}

void solve(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> taste[i];
	for(int i = 0; i < n; ++i)
		cin >> calories[i];
	cout << (go(n - 1, 0) ? go(n - 1, 0) : -1) << '\n';
}

int main(){
	fast;
	int t = 1;
	while(t--)
		solve();
	return 0;
}
