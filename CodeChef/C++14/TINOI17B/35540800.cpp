#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 5 * 1e3 + 3;
ll dp[N][N], cube[N], a[N], n;

ll solve(ll i, ll times){
	if(i == n) return 0;
	if(dp[i][times] != -1) return dp[i][times];
	ll mx = 0;
	mx = max(mx, solve(i + 1, times + 1));
	mx = max(mx, solve(i + 1, times) + (cube[times]*a[i]));
	return dp[i][times] = mx;
}

int main(){
	fast;
	ll k;
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	cube[0]  = k;
	for(int i = 1; i < N; ++i){
		ll dig = 0, kk = cube[i - 1];
		while(kk != 0){
			dig += kk%10;
			kk /= 10;
		}
		cube[i] = pow(dig, 3) + cube[i-1]; 
	}
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	cout << solve(0, 0);
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}