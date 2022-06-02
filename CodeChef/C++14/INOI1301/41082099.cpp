#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int n, k;
	cin >> n >> k;
	int a[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	if(n == 1){
		cout << "0\n";
		return 0;
	}
	int dp[n + 1] = {0}, dp2[n + 1] = {0};
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	for(int i = 3; i <= n; ++i)
		dp[i] = a[i] + max(dp[i - 2], dp[i - 1]);
	dp2[k] = 0;
	if(k + 1 <= n) 
		dp2[k + 1] = a[k + 1];
	for(int i = k + 2; i <= n; ++i)
		dp2[i] = a[i] + max(dp2[i - 1], dp2[i - 2]);
	int mx = INT_MIN;
	for(int i = k; i <= n; ++i)
		mx = max(mx, dp[i] + dp2[i] - a[i]);
	cout << mx << '\n';
	return 0;
}
