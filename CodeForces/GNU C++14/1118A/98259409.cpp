#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		ll n, a, b;
		cin >> n >> a >> b;
		if (a <= b){
			if(n % 2)
				cout << min(a + (n / 2)*b, n*a) << '\n';
			else
				cout << min(n / 2 * b, n*a) << '\n';
		}
		else if (n % 2) cout << a + (n / 2)*b << '\n';
		else cout << n / 2 * b << '\n';
	}
	return 0;
}
