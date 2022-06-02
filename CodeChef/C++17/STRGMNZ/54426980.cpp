#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define F first
#define S second
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n;

void solve(){
	cin >> n;
	long long ans = -1;
	for(ll x = 2; x*x <= n; ++x){
		if(n % x == 0){
			ans = x;
			break;
		}
	}
	if(ans == -1) ans = 1;
	else ans = n/ans;
	cout << n + ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}