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
	int ct = 0;
	for(auto k : s)
		if(k == 'a')
			++ct;
	if(ct == s.size()){
		cout << "NO\n";
		return;
	}
	if(s[0] != 'a'){
		s.push_back('a');
		cout << "YES\n";
		cout << s << "\n";
		return;
	}
	if(s[s.size() - 1] != 'a'){
		string ans = "a" + s;
		cout << "YES\n";
		cout << ans << "\n";
		return;
	}
	cout << "YES\n";
	int i = 0, j = s.size() - 1;
	while(s[i] == 'a')
		++i;
	while(s[j] == 'a')
		--j;
	if(i >= s.size() - j - 1){
		string ans = "a" + s;
		cout << ans << "\n";
		return;
	}
	else{
		s.push_back('a');
		cout << s << '\n';
	}
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
