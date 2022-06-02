#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
 
void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	int d = (b + b - a), d1 = (b - (c - b)), d2 = (c - a) / 2;
	if(d >= c and d % c == 0) cout << "YES\n";
	else if(d1 >= a and d1 % a == 0) cout << "YES\n";
	else if((c - a) % 2 == 0 and (a + d2) >= b and (a + d2) % b == 0) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}