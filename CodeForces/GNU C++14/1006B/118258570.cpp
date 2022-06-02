#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int n, k, a[N];
vector<pair<int, int> > v;

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		v.push_back({a[i], i});
	}
	sort(v.rbegin(), v.rend());
	long long ans = 0;
	vector<int> pos;
	for(int i = 0; i < k; ++i){
		ans += v[i].first;
		pos.push_back(v[i].second);
	}
	cout << ans << '\n';
	sort(pos.begin(), pos.end());
	int pre = 0;
	for(int i = 0; i < pos.size(); ++i){
	    if(i == pos.size() - 1){
	        cout << n - pre << '\n';
	        break;
	    }
		cout << pos[i] - pre << ' ';
		pre = pos[i];
	}
}
 
int main() {
	fast;
	int t = 1;
 	// cin >> t;
	while(t--)
		solve();
	return 0;
}