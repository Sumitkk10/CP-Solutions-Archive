#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	ll a, b, c;
	cin >> a >> b >> c;
	ll sum = a + b + c, mn = min({a, b, c});
	if(sum % 9 == 0 and sum/9 <= mn)
		cout << "YES\n";
	else
		cout << "NO\n";  
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
