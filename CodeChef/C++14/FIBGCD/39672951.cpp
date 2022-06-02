#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e7 + 5;
const int MOD = 1e9 + 7;
long long int f[N];

void solve(){
	long long int a, b;
	cin >> a >> b;
	cout << f[__gcd(a, b)] << '\n';
}

int main(){
	fast;
	int t;
	cin >> t;
	f[0] = 0;
	f[1] = 1;
	for(int i = 2; i < N; ++i)
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
	while(t--)
		solve();
	return 0;
}
