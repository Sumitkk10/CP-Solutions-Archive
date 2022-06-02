#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll a[N];

ll freq(ll i, ll j){
	ll hash[101] = {0};
	for(int k = i; k <= j; ++k)
		hash[a[k]]++;
	ll sum = 0;
	for(auto k : hash){ 
		if(k > 1)
			sum += k;
	}
	return sum;
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		ll dp[n + 1] = {0};
		for(int i =  1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n; ++ i){
			dp[i] = dp[i - 1] + k;
			for(int j = i - 1; j >= 1; --j)
				dp[i] = min(dp[i], dp[j - 1] + k + freq(j, i));
			// cout << dp[i] << " ";
		}
		cout << dp[n] << "\n";
	}
	return 0;
}
