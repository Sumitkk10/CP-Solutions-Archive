#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	if(a.first != b.first) 
		return a.first < b.first;
	return a.second < b.second;
}

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, k, sum = 0;
		cin >> n >> k;
		pair<ll, ll> ans[n];
		for(int i = 0; i < n; ++i){
			ll x, y;
			cin >> x >> y;
			ll dis = (x*x) + (y*y);
			ans[i].first = dis;
			ans[i].second = x + y;	
		}
		sort(ans, ans + n, cmp);
		for(int i = 0; i < k; ++i)
			sum += ans[i].second;
		cout << sum << "\n";
	}
	return 0;
}
