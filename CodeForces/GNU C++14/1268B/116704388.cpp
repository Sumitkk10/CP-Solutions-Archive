#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	int n;
	cin >> n;
	long long int ans = 0, a[n + 1], odd = 0, even = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		ans += (a[i] / 2);
		if(a[i] % 2){
			if(i % 2) ++odd;
			else ++even;
		}
	}
	cout << ans + min(odd, even) << '\n';
}

int main() {
	fast;
	int t = 1;
    // cin >> t;
	while(t--)
		solve();
}