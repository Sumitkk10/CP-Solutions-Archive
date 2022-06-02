#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n;
	cin >> n;
	ll a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(accumulate(a, a + n, 0) % 2) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
