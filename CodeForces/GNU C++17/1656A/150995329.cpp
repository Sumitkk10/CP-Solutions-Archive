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
	int mx = 0, mn = INT_MAX, res, ans;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(mn > x){
			mn = x;
			res = i;
		}
		if(mx < x){
			mx = x;
			ans = i;
		}
	}
	cout << res + 1 << ' ' << ans + 1 << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}