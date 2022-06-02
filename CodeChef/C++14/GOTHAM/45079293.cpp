#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int n;
	cin >> n;
	long long int a[n];
	multiset<pair<long long int, long long int > > s;
	for(long long int i = 0; i < n; ++i){
		cin >> a[i];
		s.insert({i, a[i]});
	}
	long long int q;
	cin >> q;
	while(q--){
		long long int x, p;
		cin >> x >> p;
		--x;
		auto pos = s.lower_bound({x, 0});
		long long int ans = 0;
		while(pos != s.end() and p > 0){
		    if(pos->second > p){
		        ans += (p * (pos->first - x ));
		        s.insert({pos->first, pos->second - p});
		        s.erase(pos);
		        p = 0;
		    }
		    else{
		        ans += (pos->second * (pos->first - x));
		        p -= pos->second;
		        auto del = pos;
		        ++pos;
		        s.erase(del);
		    }
		}
		cout << ans << '\n';
	}
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}