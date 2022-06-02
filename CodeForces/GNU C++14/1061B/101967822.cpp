#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	ll n, k;
	cin >> n >> k;
	ll a[n], sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);	ll bigger = 0;
	for(int i = 0; i < n; ++i)
		if(a[i] > bigger)
			bigger++;
	cout << sum - (n + a[n - 1] - bigger) << '\n';
}

int main(){
	fast;
	int t = 1;
	while(t--)
		solve();
	return 0;
}
