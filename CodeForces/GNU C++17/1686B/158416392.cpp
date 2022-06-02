#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;
int n, a[N];

void solve(){
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0, mx = 0;
	for(int i = 0; i < n; ++i){
		mx = max(mx, a[i]);
		if(a[i] < mx){
			mx = 0;
			++ans;
		}
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