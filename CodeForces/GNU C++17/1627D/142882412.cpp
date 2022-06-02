#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 5;
int n;

void solve(){
	cin >> n;
	int mp[N] = {0}, mx = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		mp[x]++;
	    mx = max(mx, x);
	}
	int ans = 0;
	for(int i = 1; i < mx; ++i){
		if(mp[i]) continue;
		if(i == 1){
			++ans;
			continue;
		}
		int ct = 0, wut = 0;
		for(int j = 2*i; j <= mx; j += i){
			if(mp[j])
				wut = gcd(wut, j/i);
		}
		ans += (wut == 1);
	}
	cout << ans << '\n';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
    	solve();
	return 0;
}