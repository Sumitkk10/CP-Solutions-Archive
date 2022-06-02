#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, m, k, a[20];

bool check(int i){
	if(i < k - 1) return 1;
	map<int, int> mp;
	int mx = 0;
	for(int j = i - k + 1; j <= i; ++j){
		mx = max(mx, a[j]);
		mp[a[j]]++;
	}
	if(mp[mx] >= m) return false;
	return true;
}

int go(int i){
	if(!check(i - 1)) return INT_MAX / 100;
	if(i == n)
		return 0;
	a[i] = a[i] + 1;
	int ans = INT_MAX / 100;
	ans = min(ans, go(i + 1) + 1);
	a[i] -= 1;
	ans = min(ans, go(i + 1));
	return ans;
}

void solve(){
	cin >> n >> k >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	cout << (go(0) == INT_MAX / 100 ? -1 : go(0)) << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
// 