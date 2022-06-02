#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
ll n, a[N], dp[N][3];

ll go(int i, int k){
	ll mx = 0;
	if(i >= n) return 0;
	if(dp[i][k] != -1) return dp[i][k];
	if(k < 2)
		mx = max(mx, go(i + 1, k + 1) + a[i]);
	mx = max(mx, go(i + 1, 0));
	return dp[i][k] = mx;
}

int main(){
	fast;	
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; ++i) cin >> a[i];
	cout << go(0, 0);
	return 0;
}
