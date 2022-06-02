#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int pre[n + 1] = {0};
	pre[0] = 0;
	for(int i = 1; i <= s.size(); ++i)
		pre[i] = pre[i - 1] + (s[i - 1] == '+' ? 1 : -1);
	int pre_mx[n + 1], pre_mn[n + 1];
	pre_mx[0] = pre[0];
	pre_mn[0] = pre[0];
	for(int i = 1; i <= n; ++i){
		pre_mx[i] = max(pre_mx[i - 1], pre[i]); 
		pre_mn[i] = min(pre_mn[i - 1], pre[i]);
	}
	int suf_mn[n + 2] = {0}, suf_mx[n + 2] = {0};
	suf_mx[n + 1] = suf_mn[n + 1] = pre[n];
	for(int i = n; i >= 0; --i){
		suf_mx[i] = max(suf_mx[i + 1], pre[i]);
		suf_mn[i] = min(suf_mn[i + 1], pre[i]);
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		int mn = pre_mn[l - 1];
		int mx = pre_mx[l - 1];
		int sum = pre[r] - pre[l - 1];
		mn = min(mn, suf_mn[r + 1] - sum);
		mx = max(mx, suf_mx[r + 1] - sum);
		cout << mx - mn + 1 << '\n';
	}
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
