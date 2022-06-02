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
		string s;
		cin >> s;
		map<char, int> mp;
		for(int i = 0; i < s.size(); ++i)
			mp[s[i]]++;
		bool ok = true;
		for(auto i : mp)
			if(i.second % 2 != 0)
				ok = false;
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
