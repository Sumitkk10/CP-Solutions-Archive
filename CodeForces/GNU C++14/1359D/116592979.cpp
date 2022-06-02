#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e7 + 5;

void solve(){
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	long long int mx = 0;
	for(int i = 0; i <= 30; ++i){
		bool ok = false;
		for(int j = 1; j <= n; ++j){
			if(a[j] == i){
				ok = 1;
				break;
			}
		}
		if(!ok) continue;
		vector<int> v;
		for(int j = 1; j <= n; ++j){
			if(a[j] > i) v.push_back(INT_MIN);
			else v.push_back(a[j]);
		}
		long long int sum = 0, ans = 0;
		for(auto k : v){
			sum += k;
			ans = max(ans, sum - i);
			if(sum < 0)
			    sum = 0;
		}
		mx = max(mx, ans);
		v.clear();
		// if(mx == 15) cout << i << endl;
	}
	cout << mx << '\n';
}

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}