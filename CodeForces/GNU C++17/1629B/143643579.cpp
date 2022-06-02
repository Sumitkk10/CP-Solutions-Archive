#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	long long l, r, k;
	cin >> l >> r >> k;
	if(l == 1 and r == 1){
		cout << "NO\n";
		return;
	}
	if(l == r){
		cout << "YES\n";
		return;
	}
	if(r % 2 == 0){
		if(l % 2 == 0){
			cout << (2*k >= (r - l) ? "YES\n" : "NO\n");
			return;
		}
		cout << (2*k >= (r - l + 1) ? "YES\n" : "NO\n");
		return;
	}
	if(l % 2 == 0){
		cout << (2*k >= (r - l + 1) ? "YES\n" : "NO\n");
		return;
	}
	cout << (2 * k >= (r - l + 2) ? "YES\n" : "NO\n");
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}