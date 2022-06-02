#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 305;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, total = 0;
		cin >> n;
		ll a[n], inversions[n + 1] = {0};
		for(int i = 0; i < n; ++i) cin >> a[i];
		for(int i = 0; i < n; ++i){
			int ct = 0;
			for(int j = 0; j < i; ++j)
				if(a[j] > a[i])
					++ct;
			for(int j = i + 1; j < n; ++j)
				if(a[i] > a[j])
					++ct;
			inversions[i] = ct;
			total += ct;
		}
		total /= 2;
		ll dp[total + 1] = {0};
		dp[0] = 1;
		for (int i = 0; i < n; i++)
			for (int j = total; j >= 0; j--)
				if(j + inversions[i] <= total)
					dp[j + inversions[i]] |= dp[j];
		cout << (dp[total] ? "YES\n" : "NO\n");
	}
	return 0;
}
