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
	int a[n], b[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	map<int, int> mp;
	for(int i = 0; i < n; ++i){
		cin >> b[i];
		mp[a[i] ^ b[i]]++;
	}
	int ans = 0;
	for(auto k : mp)
		ans += (k.second * (k.second - 1)) / 2;
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