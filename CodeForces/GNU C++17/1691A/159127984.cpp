#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int cnt[2] = {0};
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		cnt[x & 1]++;
	}
	cout << min(cnt[0], cnt[1]) << '\n';
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}