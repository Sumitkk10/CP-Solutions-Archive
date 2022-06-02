#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define F first
#define ll long long
#define S second
#define pb push_back
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, a[N], b[N], dp[101][10001];

long long go(int i, long long sum, long long sq, long long sum1, long long sq2){
	if(i == n){
		long long x = ((sum*sum) - sq), x1 = ((sum1 * sum1) - sq2);
		return (x + x1);
	}
	if(dp[i][sum] != -1)
		return dp[i][sum];
	long long ans = LLONG_MAX;
	ans = min(ans, go(i + 1, sum + a[i], sq + (a[i] * a[i]), sum1 + b[i], sq2 + (b[i] * b[i])));
	ans = min(ans, go(i + 1, sum + b[i], sq + (b[i] * b[i]), sum1 + a[i], sq2 + (a[i] * a[i])));
	return dp[i][sum] = ans;
}

void solve(){
	cin >> n;
	long long constant = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		constant += (n - 1) * a[i] * a[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
		constant += (n - 1) * b[i] * b[i];
	}
	memset(dp, -1, sizeof dp);
	cout << constant + go(0, 0, 0, 0, 0) << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}