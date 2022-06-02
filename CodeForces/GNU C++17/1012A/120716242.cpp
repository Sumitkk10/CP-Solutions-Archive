#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 200001;
long long n, a[N];

void solve(){
	cin >> n;
	map<int, int> mp;
	for(int i = 1; i <= 2*n; ++i){
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a + 1, a + 2*n + 1);
	int mx = 0;
	for(auto k : mp)
		mx = max(mx, k.second);
	if(mx >= n){
		cout << "0\n";
		return;
	}
	long long int mn = 1e9 + 239;
	for(int i = 2; i <= n; ++i)
		mn = min(mn, a[i + n - 1] - a[i]);
	cout << min((a[2*n] - a[1]) * mn, (a[n] - a[1]) * (a[2*n] - a[n + 1])) << '\n';
}
 
int main() {
	fast;
	int t = 1;
 	// cin >> t;
	while(t--)
		solve();
	return 0;
}