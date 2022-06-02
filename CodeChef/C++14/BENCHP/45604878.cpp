#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long n, w, W;
	cin >> n >> w >> W;
	long long a[n + 1], ans = W;
	map<int, int> mp;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		mp[a[i]]++;
		if(mp[a[i]] == 2){
			mp[a[i]] = 0;
			ans += a[i] + a[i];
		}
	}
	if(ans >= w){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
