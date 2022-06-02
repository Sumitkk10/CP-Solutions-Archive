#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n], ans[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		ans[i] = a[i];
	}
	int pre = a[0];
	for(int i = 0; i < n; ++i){
		pre = min(pre, a[i]);
		ans[i] = min(ans[i], pre);
		++pre;
	}
	pre = a[n - 1];
	for(int i = n - 1; i >= 0; --i){
		pre = min(pre, a[i]);
		ans[i] = min(ans[i], pre);
		++pre;
	} 
	for(auto k : ans) cout << k << ' ';
	cout << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
