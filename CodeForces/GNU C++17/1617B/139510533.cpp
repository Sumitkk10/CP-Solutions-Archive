#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
long long n;

void solve(){
	cin >> n;
	for(long long i = 3; i <= n; ++i){
	     if(__gcd((n - i), (i - 1)) == 1){
	          cout << (n - i) << ' ' << i - 1 << ' ' << 1 << '\n';
	          return;
	     }
	}
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
