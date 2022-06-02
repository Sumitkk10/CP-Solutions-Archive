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
	int sum = 0, mx = -INT_MAX;
	for(int i = 0; i < n; ++i){
		if(a[i] > 0){
			sum += a[i];
			mx = max(mx, a[i]);
			if(sum > mx){
				cout << "NO\n";
				return;
			}
			if(sum <= a[i]){
				sum = a[i];
				mx = a[i];
			}
			continue;
		}
		sum += a[i];
		mx = max(mx, a[i]);
	}
	sum = 0, mx = -INT_MAX;
	for(int i = 0; i < n; ++i){
		if(a[i] > 0){
			sum += a[i];
			mx = max(mx, a[i]);
			if(sum > mx){
				cout << "NO\n";
				return;
			}
			sum = a[i];
			mx = a[i];
			continue;
		}
		sum += a[i];
		mx = max(mx, a[i]);
	}
	cout << "YES\n";
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}