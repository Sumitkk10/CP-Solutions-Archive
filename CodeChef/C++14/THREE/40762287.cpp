#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	string s;
	cin >> s;
	map<char, int> mp;
	for(int i = 0; i < s.size(); ++i)
		mp[s[i]]++;
	long long int ans = 0, n = s.size();
	for(auto k : mp){
		if(k.second >= 2){
			while(k.second > 1 and n >= 3){
				k.second -= 2;
				n -= 3;
				++ans;
			}
		}
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
