/*
When I get older
I will be stronger
They'll call me freedom
Just like a wavin' flag
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long n, v;

void solve(){
	cin >> n >> v;
	// max capacity is v
	// for maximum answer he will purchase at every checkpost
	cout << (n * (n - 1)) / 2 << ' ';
	// for minimum cost he will fill full tank where ever possible.
	if(v >= n - 1){
		cout << n - 1 << '\n';
		return;
	}
	long long req = (n - 1) - v;
	long long ans = v + ((req + 1) * (req + 2))/2 - 1;
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