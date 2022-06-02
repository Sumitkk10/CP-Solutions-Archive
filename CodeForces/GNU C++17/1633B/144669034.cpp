#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define pii pair<long long, pair<int, int> >
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	string s;
	cin >> s;
	int ones = 0, zeros = 0;
	int ans = 0;
	for(int i = 0; i < s.size(); ++i){
		ones += s[i] == '1';
		zeros += s[i] == '0';
		if(ones != zeros)
			ans = max(ans, min(ones, zeros));
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
}