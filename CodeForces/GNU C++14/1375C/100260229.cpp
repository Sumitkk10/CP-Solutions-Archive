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
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	cout << (a[n - 1] > a[0] ? "YES\n" : "NO\n");
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();	
	return 0;
}
