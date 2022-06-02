#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define F first
#define S second
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;
ll n, a, b, p, q;

void solve(){
	cin >> n >> a >> b >> p >> q;
	long long ans = (n/a);
	long long res = (n/b);
	// but overcounting
	long long lcm = (a * b)/ __gcd(a, b);
	if(p >= q)
		res -= (n/lcm);
	else
		ans -= (n/lcm);
	res *= q;
	ans *= p;
	cout << ans + res << '\n';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
    	solve();
	return 0;
}