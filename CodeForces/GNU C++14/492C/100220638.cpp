#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int n, r, avr, sum = 0;
	cin >> n >> r >> avr;
	pair<ll, ll> a[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i].second >> a[i].first;
		sum += a[i].second;
	}
	sort(a, a + n);
	if(sum >= avr * n){
		cout << "0\n";
		return;
	}
	long long int ans = 0;
	int i = 0;
	// cout << sum << '\n';
	while(sum < avr * n and i < n){
		ll how_much = min(avr*n - sum, r - a[i].second);
		ans += how_much * a[i].first;
		sum += how_much;
		++i;
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
