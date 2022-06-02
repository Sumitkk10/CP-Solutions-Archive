#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	char s[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> s[i];
	int rem[3] = {0}, pre[n + 1] = {0}, suf[n + 2] = {0};
	for(int i = 1; i <= n; ++i){
		pre[i] = pre[i - 1];
		if(s[i] == 'X')
			rem[(i - 1) % 3]++;
		if(s[i] == 'Z')
			pre[i] += rem[i % 3];
	}
	rem[0] = rem[1] = rem[2] = 0;
	for(int i = n; i >= 1; --i){
		suf[i] = suf[i + 1];
		if(s[i] == 'Z')
			rem[i % 3]++;
		if(s[i] == 'X')
			suf[i] += rem[(i - 1) % 3];
	}
	int ans = INT_MAX;
	for(int i = 1; i <= n - k + 1; ++i)
		ans = min(ans, suf[1] - suf[i + k] - pre[i - 1]);
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
