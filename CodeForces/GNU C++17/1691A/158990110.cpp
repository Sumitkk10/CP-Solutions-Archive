#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;


void solve(){
	int n;
	cin >> n;
	int odd = 0, even = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x % 2) ++odd;
		else ++even;
	}
	cout << min(odd, even) << '\n';
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}