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
		ll n, x, p, k;
		cin >> n >> x >> p >> k;
		// x = tar
		// p = place of target
		// k = place which we can repalce with
		ll a[n + 1] = {0};
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		if(a[p] < x && k > p || a[p] > x && k < p){
			cout << "-1\n";
			continue;
		}
		if(a[p] == x){
			cout << "0\n";
			continue;
		}
		if(a[p] <= x && k <= p){
			ll ans = 0;
			for(int i = p; i <= n; ++i)
				ans += (a[i] < x);
			if(ans == 0) ++ans;
			cout << ans << "\n";
			continue;
		}
		if(a[p] >= x && k >= p){
			ll ans = 0;
			for(int i = k - 1; i >= 1; --i)
				ans += (a[i] <= x);
			++ans;
			cout << p - ans + 1 << "\n";
		}
	}
	return 0;
}