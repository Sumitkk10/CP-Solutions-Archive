#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = (n % 2 == 1), l = n / 2 - 1;
	char x = s[n / 2];
	while(l >= 0){
		if(s[l] == x)
			ans += 2;
		else break;
		--l;
	}
	cout << ans << '\n';
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}