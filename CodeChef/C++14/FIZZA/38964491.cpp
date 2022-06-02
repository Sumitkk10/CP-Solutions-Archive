#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll a[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		ll dp[n] = {0};
		for(int i = 1; i < n; ++i){
			if(a[i] == a[i - 1]) dp[i] += dp[i - 1] + 1;
			else if(a[i] == a[i - 2] && i != 1) dp[i] += dp[i - 2] + 1;
		}
		cout << *max_element(dp, dp + n) << "\n"; 
	}
	return 0;
}
