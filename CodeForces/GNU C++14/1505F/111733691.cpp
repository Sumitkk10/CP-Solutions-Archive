#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int x;
	cin >> x;
	cout << (2 - x*x) << "\n"; 
}

int main(){
    fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}