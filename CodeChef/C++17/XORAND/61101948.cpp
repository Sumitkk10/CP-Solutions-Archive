#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	map<int, long long> cnt;
	for(int i = 0; i < n; ++i){
		long long x;
		cin >> x;
		cnt[log2(x) + 1]++;
	}
	long long ans = 0;
	for(auto k : cnt)
		ans += (k.second * (k.second - 1)) / 2;
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1, tt = 1;
	cin >> t;
	while(t--){
		// cout << "Case #" << tt << ": ";
		solve();
		// ++tt;
	}
	return 0;
}