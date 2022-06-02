#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	map<int, int> mp;
	map<int, bool> done;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		mp[a[i]]++;
	}
	long long ans = 0;
	set<int> v;
	for(int i = 1; i <= n; ++i){
		ans += (mp[i] > 0);
		if(!mp[i])
			v.insert(i);
	}
	sort(a, a + n);
	ans = n - ans;
	for(int i = 0; i < n; ++i){
		if(a[i] > n or done[a[i]]){
			int cur = *v.begin();
			if(2*cur >= a[i]){
				cout << "-1\n";
				return;
			}
			v.erase(--v.upper_bound((a[i] - 1)/2));
		}
		done[a[i]] = true;
	}
	cout << ans << '\n';
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
