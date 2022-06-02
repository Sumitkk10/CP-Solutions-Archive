#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if(a > b + c) cout << '+';
    else if(a + c < b) cout << '-';
    else if(a == b && c == 0) cout << '0';
    else cout << '?';

}

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	return 0;
}
