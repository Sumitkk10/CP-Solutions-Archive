#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int n;
	cin >> n;
	if(n < 10)
		cout << n << '\n';
	else if(n < 100)
		cout << 2 * (n + 1) - 11 << '\n'; 
	else{
		string s = to_string(n);
		int len = s.size();
		ll ans = len * (n + 1);
		for(int i = 0; i < len; ++i)
			ans -= pow(10, i);
		cout << ans << '\n';
	}
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}