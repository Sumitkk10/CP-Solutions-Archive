#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int pre[n + 1][n + 1], suf[n + 2][n + 2];
	memset(pre, 0, sizeof pre);
	memset(suf, 0, sizeof suf);
	for(int i = 1; i <= n; ++i){
		for(int j = a[i] + 1; j <= n; ++j)
			pre[i][j] = pre[i - 1][j] + 1;
		for(int j = 1; j <= a[i]; ++j)
			pre[i][j] = pre[i - 1][j];
	}
	for(int i = n; i >= 1; --i){
		for(int j = a[i] + 1; j <= n; ++j)
			suf[i][j] = suf[i + 1][j] + 1;
		for(int j = 1; j <= a[i]; ++j)
			suf[i][j] = suf[i + 1][j];
	}
	long long ans = 0;
	for(int i = 2; i <= n - 2; ++i)
		for(int j = i + 1; j <= n - 1; ++j)
			ans += (pre[i - 1][a[j]] * suf[j + 1][a[i]]);
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}