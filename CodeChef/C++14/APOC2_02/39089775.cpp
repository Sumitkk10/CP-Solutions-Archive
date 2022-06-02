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
		ll n, k;
		cin >> n >> k;
		ll a[n + 1];
		set<ll> distinct;
		map<ll, ll> mp;
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
			distinct.insert(a[i]);
		}
		ll sum = 0, ans = 0;
		for(int i = 1; i <= k; ++i){
			mp[a[i]]++;
			sum += a[i];
		}
		if(mp.size() == distinct.size())
			ans = max(ans, sum);
		for(int i = 2; i <= n - k + 1; ++i){
			mp[a[i - 1]]--;
			if(mp[a[i - 1]] == 0)
				mp.erase(a[i - 1]);
			mp[a[i + k - 1]]++;
			sum -= a[i - 1];
			sum += a[i + k - 1];
			// cout << mp.size() << " ";
			if(mp.size() == distinct.size())
				ans = max(ans, sum); 
		}
		cout << ans << "\n";
	}
	return 0;
}
