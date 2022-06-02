#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll h[N], r[N];

int32_t main(){
	fast;
	ll n, w, l;
	cin >> n >> w >> l;
	for(int i = 0; i < n; ++i)
		cin >> h[i] >> r[i];
	ll low = 0, high = 1e18;
	while(low < high){
		ll mid = low + (high - low) / 2;
		ll ans = 0;
		for(int i = 0; i < n; ++i){
			ll height = h[i] + (mid * r[i]);
			if(height >= l){
				ans += height;
				if(ans >= w) break;
			}
		}
		if(ans >= w)
			high = mid;
		else 
			low = mid + 1;
	}
	cout << low << "\n";
	return 0;
}
