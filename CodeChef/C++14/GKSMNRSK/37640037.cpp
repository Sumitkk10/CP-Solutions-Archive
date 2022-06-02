#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll t;
	cin >> t;	
	while(t--){
		ll n; 
		cin >> n;
		ll a[n];
		map<int, int> mp;
		for(int i = 0; i < n; ++i) cin >> a[i], mp[a[i]]++;
		priority_queue<int> q;
		for(auto i : mp) q.push(i.second);
		ll ans = 0;
		while(q.size() > 1){
			++ans;
			ll x = q.top();
			q.pop();
			ll y = q.top();
			q.pop();
			--x, --y;
			if(x) q.emplace(x); 
			if(y) q.emplace(y);
		}
		if(!q.empty()) ans += q.top();
		cout << ans << "\n";
	}
	return 0;
}
