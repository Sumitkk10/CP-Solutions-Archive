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
		set<ll> s, ss;
		ll n; cin >> n;
		for(int i = 0; i < n; ++i){
			int x; cin >> x;
			if(x > 0) s.insert(x);
			else ss.insert(x);
		}
		long long int sum = 0;
		for(auto k : s) sum += k;
		cout << sum << " ";
		sum = 0;
		for(auto k : ss) sum += k;
		cout << sum << "\n";
	}
	return 0;
}
