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
		ll n, mx = 0; cin >> n;
		map<string, int> mp;
		for(int i = 0; i < n; ++i){
			string s; cin >> s;
			mp[s]++;
		}
		string ans = "zzzzzzzzzzzzzzzzzz";
		for(auto i : mp){
			if(i.second >= mx){
				if(i.first < ans && i.second == mx) 
					ans = i.first;
				else if(i.second != mx) ans = i.first;
				mx = i.second;
			}
		}
		cout << ans << "\n";
	}
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}