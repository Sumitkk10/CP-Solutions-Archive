#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 25;

void solve(){
	int n, x;
	cin >> n >> x;
	int sum = x;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		sum += a;
	}
	cout << (sum <= 24 ? "YES\n" : "NO\n");
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}