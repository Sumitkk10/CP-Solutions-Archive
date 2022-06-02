#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
long long int n, a[N], pre[N], suf[N];

void solve(){
	cin >> n;
	map<long long, int> mp;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
		mp[pre[i]] = i;
	}
	for(int i = n; i >= 1; --i)
		suf[i] = suf[i + 1] + a[i];
	long long ans = 0;
	for(int i = 1; i <= n; ++i){
		if(pre[i] == suf[i + 1])
			ans = max(ans, pre[i]);
		else if(suf[i] == pre[i - 1])
			ans = max(ans, suf[i]);
	}
	for(int i = 1; i <= n; ++i){
		if(mp[suf[i]])
			if(mp[suf[i]] < i)
				ans = max(ans, suf[i]);
	}
	cout << ans << '\n';
}
 
int main() {
	fast;
	int t = 1;
 	// cin >> t;
	while(t--)
		solve();
	return 0;
}