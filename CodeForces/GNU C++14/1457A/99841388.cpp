#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	cout << max({abs(r - 1) + abs(c - 1), abs(r - n) + abs(c - m), abs(r - n) + abs(c - 1), abs(r - 1) + abs(c - m)}) << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
