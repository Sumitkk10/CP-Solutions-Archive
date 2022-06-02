#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;
ll sum = -INT_MAX;

int main(){
	fast;
	ll n, k;
	cin >> n >> k;
	--k;
	ll dp[n] = {0}, dp1[n] = {0}, a[n];
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	dp[k+1] = a[k+1];
	for(int i = k+2; i < n; ++i)
		dp[i] = max(dp[i-2], dp[i-1]) + a[i];
	dp1[1] = a[0];
	for(int i = 2; i < n; ++i)
		dp1[i] = max(dp1[i-1] + a[i-1], dp1[i-2] + a[i-2]);
	for(int i = k; i < n; ++i)
		sum = max(sum, dp[i] + dp1[i]);
	cout << sum; 
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}