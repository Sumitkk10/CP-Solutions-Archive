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
		string s;
		cin >> s;
		map<char, int> mp;
		for(int i = 0; i < s.size(); ++i)
			mp[s[i]]++;
		ll ans = 0;
		for(auto k : mp)
			if(k.second > 0)
				++ans;
		cout << ans << "\n";
	}
	return 0;
}
