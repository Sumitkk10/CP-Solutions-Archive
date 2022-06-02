#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e8;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<string, int> mp;
	for(int i = 1; i < n; ++i){
		string a;
		a.push_back(s[i - 1]);
		a.push_back(s[i]);
		mp[a]++;
	}
	string ans;
	int mx = 0;
	for(auto k : mp){
		if(k.second > mx){
			mx = k.second;
			ans = k.first;
		}
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
