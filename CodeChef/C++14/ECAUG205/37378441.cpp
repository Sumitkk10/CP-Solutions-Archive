#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t; cin >> t;
	while(t--){
		ll n, k; cin >> n >> k;
		ll a[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		ll low = 1, high = 1e12, anss = 0;
		while(low <= high){
			ll mid = (low + high) / 2;
			ll ans = 0;
			for(int i = 0; i < n; ++i) ans += a[i]/mid;
			if(ans >= k){
				low = mid + 1;
				anss = mid; 
			}
			else 
				high = mid - 1;
		}
		cout << anss << "\n";
	}
	return 0;
}
