#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	ll n;
	cin >> n;
	pair<long long int, long long int> input[n];
	for(int i = 0; i < n; ++i)
		cin >> input[i].second;
	for(int i = 0; i < n; ++i)
		cin >> input[i].first;
	sort(input, input + n);
	long long int ans = 0, remaining = n;
	for(int i = 0; i < n; ++i){
		long long int mn = min(remaining, input[i].second);
		ans += input[i].first * mn;
		remaining -= mn;
		if(!remaining)
			break;
	}
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
