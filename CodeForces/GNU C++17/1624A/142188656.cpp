#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
 
void solve(){
	int n;
	cin >> n;
	int a[n], mx = 0, mn = INT_MAX;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	cout << mx - mn << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}