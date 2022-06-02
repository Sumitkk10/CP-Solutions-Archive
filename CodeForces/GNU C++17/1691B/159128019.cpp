#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;


void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 1; i < n - 1; ++i){
		if(a[i] != a[i - 1] and a[i] != a[i + 1]){
			cout << "-1\n";
			return;
		}
	}
	if(a[0] != a[1]){
		cout << "-1\n";
		return;
	}
	if(a[n - 1] != a[n - 2]){
		cout << "-1\n";
		return;
	}
	for(int i = 0; i < n; ++i){
		int x = a[i], ct = 0, j = i;
		while(j < n and a[j] == x){
			++ct;
			++j;
		}
		--j;
		for(int k = i + 1; k <= j; ++k)
			cout << k + 1 << ' ';
		cout << i + 1 << ' ';
		i = j;
	}
	cout << '\n';
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}