#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll a, b;

bool check(ll mid){
	ll mx = max(a, b), mn = min(a, b);
	if(mid > mn)
	     return false;
	if(mn + mx >= 4*mid) return true;
	return false;
}

void solve(){
	cin >> a >> b;
	ll low = 1, high = 1e9, ans = 0;
	while(low <= high){
		ll mid = (low + high) / 2;
		if(check(mid)){
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}