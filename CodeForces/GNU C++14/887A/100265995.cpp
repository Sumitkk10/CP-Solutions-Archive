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
	bool ok = 0;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '1') ok = 1;
		if(s[i] == '0' and ok)
			++ct;
	}
	cout << (ct >= 6 ? "yes" : "no");
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
