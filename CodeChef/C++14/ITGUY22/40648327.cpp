#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int x, y;
	cin >> x >> y;
	long long int lcm = (x * y) / (__gcd(x, y));
	cout << (lcm / x) + (lcm / y) - 2 << '\n';
}	

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}