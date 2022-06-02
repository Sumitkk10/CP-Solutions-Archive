#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i){
		int sum = 0;
		for(int j = 0; j < n; ++j){
			if(i == j) continue;
			sum += a[j];
		}
		if(a[i] * (n - 1) == sum){
			cout << "Yes\n";
			return;
		}
	}
	cout << "NO\n";
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}