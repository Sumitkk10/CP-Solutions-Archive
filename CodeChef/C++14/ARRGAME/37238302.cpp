#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll a[n], mx = 0, ans = 0;
		for(int i = 0; i < n; ++i) cin >> a[i];
		for(int i = 0; i < n; ++i){
			ll ct = 0;
			while(a[i] == 0 && i < n){
				i++;
				++ct;
			}
			mx = max(mx, ct);
			ct = 0;
		}
		for(int i = 0; i < n; ++i){
			ll ct = 0;
			while(a[i] == 0 && i < n){
				i++;
				++ct;
			}
			if(ct == mx) ++ans;
			ct = 0;
		}
		ll yo = -1;
		for(int i = 0; i < n; ++i){
			ll ct = 0;
			while(a[i] == 0 && i < n){
				i++;
				++ct;
			}
			if(ct < mx && ct >= yo && ct != 0) yo = ct;
			ct = 0;
		}
		if(ans > 1) cout << "No\n";
		else if(mx % 2 == 0) cout << "No\n";
		else if(yo >= (mx + 1) /2 && yo != -1) cout << "No\n";
		else cout << "Yes\n";
	}
	return 0;
}
