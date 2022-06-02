#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


void solve(){
	int n;
	cin >> n;
	int a[n], mn = INT_MAX;
	vector<int> check(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	check[0] = a[0];
	for(int i = 1; i < n; ++i)
		check[i] = __gcd(check[i - 1], a[i]);
	for(int i = 0; i < n; ++i){
		if(check[i] != a[i]){
			cout << "-1\n";
			return;
		}
	}
	for(auto k : check)
		cout << k << ' ';
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