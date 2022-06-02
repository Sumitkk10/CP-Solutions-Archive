#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	string s, t;
	cin >> s >> t;
	map<char, int> mp;
	for(auto k :s)
		mp[k]++;
	if(!mp['a'] or !mp['b'] or !mp['c']){
		sort(s.begin(), s.end());
		cout << s << '\n';
		return;
	}
	if(t[0] != 'a'){
		sort(s.begin(), s.end());
		cout << s << '\n';
		return;
	}
	if(t[1] != 'b'){
		sort(s.begin(), s.end());
		cout << s << '\n';
		return;
	}
	sort(s.begin(), s.end());
	string ans;
	for(int i = 0; i < 26; ++i){
		char x = i + 'a';
		if(i == 1){
			x = i + 'a' + 1;
			while(mp[x]--)
				ans.push_back(x);
			x = i + 'a';
			while(mp[x]--)
				ans.push_back(x);
			++i;
			continue;
		}
		while(mp[x]--)
			ans.push_back(x);
	}
	cout << ans << '\n';
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
