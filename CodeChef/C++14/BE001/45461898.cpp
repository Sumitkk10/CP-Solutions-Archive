#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 25;
long long fact[102];

void solve(){
	int n, x, y;
	cin >> n >> x >> y;
	long long a = fact[n] / (fact[x] * fact[n - x]);
	long long b = fact[n] / (fact[y] * fact[n - y]);
	cout << a * b << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	fact[0] = fact[1] = 1;
	for(int i = 2; i <= 101; ++i)
		fact[i] = fact[i - 1] * i;
	while(t--)
		solve();
	return 0;
}