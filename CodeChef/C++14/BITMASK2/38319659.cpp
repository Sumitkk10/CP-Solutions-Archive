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
		ll a[n], b[n];
		for(int i = 0; i < n; ++i) cin >> a[i];
		for(int i = 0; i < n; ++i) cin >> b[i];
		ll ans = 0;
		sort(a, a + n);
		sort(b, b + n, greater<int>());
		for(int i = 0; i < n; ++i)
			ans += a[i]*b[i];
		cout << ans << "\n"; 
	}
	return 0;
}
