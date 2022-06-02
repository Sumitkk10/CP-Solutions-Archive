#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int ans = 0;
	string s;
	cin >> s;
	int ok = s[0] - 'a' + 1;
	ok *= 100;
	for(int i = 0; i < s.size(); ++i){
		int okk = s[i] - 'a';
		ans = (ans + okk + ok) % MOD;
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
