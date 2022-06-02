#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, q;
	cin >> n >> q;
	int a[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 1;
	for(int j = 2; j <= n; ++j){
		while(a[j] != a[j - 1] && j <= n){
			++ans;
			++j;
		}
	}
	while(q--){
		int i, x;
		cin >> i >> x;
		int y = a[i];
		if(a[i] == a[i - 1] && i != 1 && x != a[i - 1]) ++ans;
		if(a[i] == a[i + 1] && i != n && x != a[i + 1]) ++ans;
		if(a[i] != a[i - 1] && i != 1 && x == a[i - 1]) --ans;
		if(a[i] != a[i + 1] && i != n && x == a[i + 1]) --ans; 
		a[i] = x;
		cout << ans << '\n';
	}
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
