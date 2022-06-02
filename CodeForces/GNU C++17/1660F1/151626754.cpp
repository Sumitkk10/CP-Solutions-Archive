#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 2e5 + 5, MOD = 998244353;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = ' ' + s;
	int pre_0[n + 1], pre_1[n + 1];
	pre_0[0] = 0;
	pre_1[0] = 0;
	for(int i = 1; i <= n; ++i){
		pre_0[i] = pre_0[i - 1];
		pre_1[i] = pre_1[i - 1];
		if(s[i] == '-')
			pre_0[i]++;
		else
			pre_1[i]++;
	}
	int ans = 0;
	for(int l = 1; l <= n; ++l){
		for(int r = l + 1; r <= n; ++r){
			int pos = pre_1[r] - pre_1[l - 1];
			int neg = pre_0[r] - pre_0[l - 1];
			int x = neg - pos;
			if(x < 0) continue;
			if(x%3== 0) ++ans;
		}
	}
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