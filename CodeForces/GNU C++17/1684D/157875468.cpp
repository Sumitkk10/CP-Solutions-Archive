#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	long long a[n + 1];
	vector<pair<long long, int> > res;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		res.pb({a[i] - (n - i), i});
	}
	if(n == k){
		cout << "0\n";
		return;
	}
	sort(res.rbegin(), res.rend());
	vector<int> jump;
	for(int i = 0; i < k; ++i)
		jump.pb(res[i].S);
	sort(jump.begin(), jump.end());
	long long extra = 0, j = 0, ans = 0;
	for(int i = 1; i <= n; ++i){
		if(i == jump[j]){
			++j;
			++extra;
			continue;
		}
		ans += a[i] + extra;
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