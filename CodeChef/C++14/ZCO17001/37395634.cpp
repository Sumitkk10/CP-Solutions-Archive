#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll n, t; 
	cin >> n >> t;
	ll a[n];
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	vector<pair<ll, ll> > mp;
	vector<ll> idx[N];
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			ll sum = a[i] + a[j];
			if(sum >= t) continue;
			mp.push_back({sum, j});
			idx[sum].push_back(i);
			
		}
	}
	ll ans = 0;
	for(int i = 0; i < mp.size(); ++i){
		ll sum = t - mp[i].first;
		ll k = lower_bound(idx[sum].begin(), idx[sum].end(), mp[i].second + 1) - idx[sum].begin();
		ans += idx[sum].size() - k;
	}
	cout << ans;
	return 0;
}