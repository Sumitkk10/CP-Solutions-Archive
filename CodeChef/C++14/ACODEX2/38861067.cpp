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
	ll ans = 0;
	while(n--){
		int a, b, c, ct = 0;  
		cin >> a >> b >> c;
		if(a == 1) ++ct;
		if(b == 1) ++ct;
		if(c == 1) ++ct;
		if(ct >= 2) ++ans;
	}
	cout << ans << "\n";
	return 0;
}
