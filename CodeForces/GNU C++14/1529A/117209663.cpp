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
	long long a[n + 1], mn = 101;
	map<int, int> mp;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		mp[a[i]]++;
		mn = min(mn, a[i]);
	}
	cout << n - mp[mn] << '\n';
}

int main() {
	fast;
	int t = 1;
     cin >> t;
	while(t--)
		solve();
}