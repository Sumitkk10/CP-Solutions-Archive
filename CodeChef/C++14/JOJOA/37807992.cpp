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
		ll n = s.size();
		for(auto k : s) mp[k]++;
		ll distinct = mp.size();
		ll str = 0, end = -1, strt = -1, siz = 1e18;
		mp.clear();
		for(int i = 0; i < n; ++i){
			mp[s[i]]++;
			if(mp.size() != distinct) continue;
			while(mp[s[str]] > 1){
				mp[s[str]]--;
				str++;
			}
			if((i - str + 1) < siz){
				end = i;
				strt = str;
				siz = end - str + 1;
			}
		}
		for(int i = strt; i <= end; ++i)
			cout << s[i] - 'a' + 1;
		cout << "\n";
 	}
	return 0;
}
