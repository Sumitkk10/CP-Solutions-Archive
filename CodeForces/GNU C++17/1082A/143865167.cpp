#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
long long n, x, y, d;

void solve(){
	cin >> n >> x >> y >> d;
	if(d == 1){
		cout << abs(y - x) << '\n';
		return;
	}
	if((x % d) == (y % d)){
		cout << abs(y - x) / d << '\n';
		return;
	}
	long long res = 1e12;
	if(y % d == 1)
		res = min(res, (x + d - 1)/d + y/d);
	if(y % d == (n % d))
		res = min(res, (n - x + d - 1)/d + (n - y)/d);
	cout << (res == 1e12 ? -1 : res) << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}