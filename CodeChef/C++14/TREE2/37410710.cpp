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
		ll a[n];
		set<ll> s;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			if(!a[i]) continue;
			s.insert(a[i]);
		}
		cout << s.size() << "\n";
	}
	return 0;
}
