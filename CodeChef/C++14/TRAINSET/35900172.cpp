#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		map<pair<string, int>, int> mp;
		set<string> st;
		for(int i = 0; i < n; ++i){
			string s;
			int x;
			cin >> s >> x;
			mp[{s, x}]++;
			st.insert(s);
		}
		int ans = 0;
		for(auto i : st)
			ans += max(mp[{i, 0}], mp[{i, 1}]);
		cout << ans << "\n";
	}
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}